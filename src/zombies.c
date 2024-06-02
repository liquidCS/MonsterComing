#ifndef ZOMBIES_C
#define ZOMBIES_C

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "raylib.h"
#include "zombies.h"
#include "coins.h"
#include "mainPlayer.h"
#include "basic.h"
#include "saveHandler.h"
#include "mainGameGUI.h"

// Save All Zombie Texture
Texture2D zombieTextures[ZombieTypesCount];
// Zombies
zombie *zombies, *lastZombie;
zombieDamage *damageAnimation;
int ZombieCount;


void initZombies(){
    
    // Initilize Zombies Link List
    zombies = (zombie *) malloc(sizeof(zombie));
    (*zombies) = (zombie){.zombieType=FIRSTNODEZOMBIE, .nextZombie = NULL};
    lastZombie = zombies;
    // Initilize Zombies Damage Animation
    damageAnimation = (zombieDamage *)malloc(sizeof(zombieDamage));
    (*damageAnimation) = (zombieDamage){.damage = -1};
    // Load Texture
    zombieTextures[LEVEL1V1] = LoadTexture("resources/zombies/zombie1.png");
    zombieTextures[LEVEL1V2] = LoadTexture("resources/zombies/zombie2.png");

    return;
}

zombie * createNewZombie(int zombieType, Vector2 position){
    zombie *newZombie = (zombie *)malloc(sizeof(zombie));
    if(zombieType == LEVEL1V1){
        newZombie -> zombieType = zombieType;
        newZombie -> maxHealth = 10;
        newZombie -> health = 10;
        newZombie -> speed = 50;
        newZombie -> dropXP = 10;
        newZombie -> dropCoin = 1;
        newZombie -> position = position;
    }
    else if(zombieType == LEVEL1V2){
        newZombie -> zombieType = zombieType;
        newZombie -> maxHealth = 20;
        newZombie -> health = 20;
        newZombie -> speed = 55;
        newZombie -> dropXP = 20;
        newZombie -> dropCoin = 2;
        newZombie -> position = position;
    }
    newZombie -> hitbox = (Rectangle) {position.x, position.y, ZOMBIE_SIZE, ZOMBIE_SIZE};
    newZombie -> center = (Vector2){newZombie->position.x + newZombie->hitbox.width/2, newZombie->position.y + newZombie->hitbox.height/2};
    newZombie -> nextZombie = NULL;
    ZombieCount++; // Add 1 Zombie to Count
    return newZombie;
}

void spawnZombie(int zombieType, Vector2 position){
    // Create New Zombie and Add it to Link List

    lastZombie->nextZombie = createNewZombie(zombieType, position);
    // Update lastZombie to newly created zombie
    lastZombie = lastZombie->nextZombie;

    return;
}

void killZombie(zombie *priorZombie, zombie *targetZombie){
    // Add to Statistic
    writeCurrStatistic(ZOMBIESKILLED, 1);
    // Drop Coins
    spawnCoin(targetZombie->center, targetZombie->dropCoin);
    // free Zombie
    priorZombie->nextZombie = targetZombie->nextZombie;
    lastZombie = priorZombie;
    free(targetZombie);
    ZombieCount--; // Decrease 1 Zombie Count
    return;
}

void drawZombies(){
    static int currFrame = 0;
    static float currTime = 0.0f;
    zombie * currZombie = zombies;
    
    // Calculate with Frame to Draw
    currTime += GetFrameTime();
    if(currTime >= ZOMBIE_ANIMATION_TIME){
        currTime = 0.0f;
        currFrame = currFrame + 1 >= ZOMBIE_FRAMES ? 0 : currFrame+1;
    }

    // Draw Zombies
    while(currZombie != NULL){
        if(currZombie->zombieType != FIRSTNODEZOMBIE){
            // Draw Zombie Texture with Animation
            Rectangle source = { currFrame*ZOMBIE_SIZE, currZombie->facing*ZOMBIE_SIZE, ZOMBIE_SIZE, ZOMBIE_SIZE};
            Rectangle dest = {currZombie->position.x, currZombie->position.y, ZOMBIE_SIZE, ZOMBIE_SIZE};
            DrawTexturePro(zombieTextures[currZombie->zombieType], source, dest, (Vector2){0, 0}, 0, WHITE);
            
            // Draw Zombie health if zombie isn't at max health
            if(currZombie->health != currZombie->maxHealth){
                DrawRectangle(currZombie->position.x, currZombie->position.y - LEVEL1_HEALTHBAR_HEIGHT, currZombie->hitbox.width, LEVEL1_HEALTHBAR_HEIGHT, RED);
                DrawRectangle(currZombie->position.x, currZombie->position.y - LEVEL1_HEALTHBAR_HEIGHT, ((float)currZombie->health/currZombie->maxHealth)*currZombie->hitbox.width, LEVEL1_HEALTHBAR_HEIGHT, GREEN);
            }

            #if DEBUG == 1
                DrawRectangleLines(currZombie->hitbox.x, currZombie->hitbox.y, currZombie->hitbox.width, currZombie->hitbox.height, RED);
            #endif
        }
        // Next Zombie Node
        currZombie = currZombie->nextZombie;
    }
}

void zombieMovement(){
    zombie *currZombie = zombies;
    Vector2 oldPosition;
    float dt = GetFrameTime();

    while(currZombie != NULL){
        if(currZombie->zombieType != FIRSTNODEZOMBIE) {
            oldPosition = currZombie->position;
            // calculate direction to player
            float radian = atanf(fabs((getMainPlayerCenter().y - currZombie->center.y)/(getMainPlayerCenter().x - currZombie->center.x)));
            float x = getMainPlayerCenter().x - currZombie->center.x > 0 ? 1.0 : -1.0;
            float y = getMainPlayerCenter().y - currZombie->center.y > 0 ? 1.0 : -1.0;
            currZombie->position.x += currZombie->speed*cos(radian)*dt*x;
            currZombie->position.y += currZombie->speed*sin(radian)*dt*y;

            // update zombie facing direction
            if(x >= 0)
                currZombie->facing = RIGHT;
            else
                currZombie->facing = LEFT;
        }

        // Update Hitbox
        currZombie->hitbox.x = currZombie->position.x;
        currZombie->hitbox.y = currZombie->position.y;
        // Update Center
        currZombie->center.x = currZombie->position.x + currZombie->hitbox.width/2;
        currZombie->center.y = currZombie->position.y + currZombie->hitbox.height/2;
        
        // Next Zombie Node
        currZombie = currZombie->nextZombie;
    }
    return;
}

/// problem
void zombieCheck(){
    zombie *currZombie = zombies, *prevZombie = currZombie, *nextZombie;
    while(currZombie != NULL){
        if(currZombie->zombieType != FIRSTNODEZOMBIE){
            if(currZombie->health <= 0){
                nextZombie = currZombie->nextZombie;
                killZombie(prevZombie, currZombie);
                currZombie = nextZombie;
            }
            else{
                prevZombie = currZombie;
                currZombie = currZombie->nextZombie;
            }
        }
        else{
            currZombie = currZombie->nextZombie;
        }
    }
}

// Free Zombie
void freeAllZombie(){
    zombie *currZombie = zombies, *nextZombie;
    while(currZombie != NULL){
        nextZombie = currZombie->nextZombie;
        free(currZombie);
        currZombie = nextZombie;
    }
    free(currZombie);
    return;
}

zombie * getZombies(){
    return zombies;
}



// Draw ZombieDamage
void addZombieDamageAnimation(zombie *targetZombie, int damage, damageTypes damageType){
    zombieDamage *currAnimation = damageAnimation;
    while(currAnimation->nextDamage != NULL){
        currAnimation = currAnimation->nextDamage;
    }
    currAnimation->nextDamage = (zombieDamage *)malloc(sizeof(zombieDamage)); // create new animation
    currAnimation = currAnimation->nextDamage;
    Vector2 animationPos = {targetZombie->position.x + rand()%(int)targetZombie->hitbox.width, targetZombie->position.y - 40}; 
    if(damageType == NORMAL)
        *currAnimation = (zombieDamage){damage, animationPos, NORMAL, 0, NORMAL_DAMAGE_TIME, NULL};
    else if(damageType == CRITICAL)
        *currAnimation = (zombieDamage){damage, animationPos, CRITICAL, 0, CRITICAL_DAMAGE_TIME, NULL};
    return;
}

void drawZombieDamageValue(){
    char animationText[10];
    int animationFontSize;
    Color animationColor;
    zombieDamage *currAnimation = damageAnimation, *prevAnimation = currAnimation;
    while(currAnimation != NULL){
        if(currAnimation->damage != -1){
            itoa(currAnimation->damage, animationText, 10); // int to string
            animationFontSize = currAnimation->damageType == NORMAL ? NORMAL_DAMAGE_FONTSIZE : CRITICAL_DAMAGE_FONTSIZE; // Assign FontSize
            animationColor = currAnimation->damageType == NORMAL ? NORMAL_DAMAGE_COLOR : CRITICAL_DAMAGE_COLOR;// Assign Colors
            // Draw 
            DrawText(animationText, currAnimation->position.x, currAnimation->position.y, animationFontSize, animationColor);
            // Add Time to currNode and check
            currAnimation->currTime += GetFrameTime();
            if(currAnimation->currTime >= currAnimation->existTime){
                prevAnimation->nextDamage = currAnimation->nextDamage;
                free(currAnimation);
                currAnimation = prevAnimation;
            }
            else{
                prevAnimation = currAnimation;
            }
        }
        currAnimation = currAnimation->nextDamage;
    }    
    return; 
}

int getZombieCount(){
    return ZombieCount;
}



#endif