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


// Save All Zombie Texture
Texture2D zombieTextures[ZombieTypesCount];
// Zombies
zombie *zombies, *lastZombie;


void initZombies(){
    
    // Initilize Zombies Link List
    zombies = (zombie *) malloc(sizeof(zombie));
    (*zombies) = (zombie){.zombieType=FIRSTNODEZOMBIE, .nextZombie = NULL};
    lastZombie = zombies;
    // Load Texture
    zombieTextures[ZTEMP1] = LoadTexture("resources/zombies/tempZombie.png");
    
    return;
}

zombie * createNewZombie(int zombieType, Vector2 position){
    zombie *newZombie = (zombie *)malloc(sizeof(zombie));
    if(zombieType == ZTEMP1){
        newZombie -> zombieType = zombieType;
        newZombie -> maxHealth = 10;
        newZombie -> health = 10;
        newZombie -> speed = 50;
        
        newZombie -> dropXP = 10;
        newZombie -> dropCoin = 1;
        
        newZombie -> position = position;
        newZombie -> hitbox = (Rectangle) {position.x, position.y, 32.0f, 32.0f};
    }
    newZombie -> center = (Vector2){newZombie->position.x + newZombie->hitbox.width/2, newZombie->position.y + newZombie->hitbox.height/2};
    newZombie -> nextZombie = NULL;
    return newZombie;
}

void spawnZombie(int zombieType){
    // Create New Zombie and Add it to Link List
    if(zombieType == ZTEMP1){
        lastZombie->nextZombie = createNewZombie(ZTEMP1, getMainPlayerLoc());
    }
    // Update lastZombie to newly created zombie
    lastZombie = lastZombie->nextZombie;

    return;
}

void killZombie(zombie *priorZombie, zombie *targetZombie){
    
    // Drop Coins
    spawnCoin(targetZombie->center, targetZombie->dropCoin);
    // free Zombie
    priorZombie->nextZombie = targetZombie->nextZombie;
    lastZombie = priorZombie;
    free(targetZombie);
    return;
}

void drawZombieDamageValue(zombie *targetZombie, int damage){
    char num[10];
    sprintf(num, "%d", damage);
    DrawText(num, targetZombie->position.x + rand()%(int)targetZombie->hitbox.width, targetZombie->position.y - 30 , 15, RED);
    return;
}


void drawZombies(){
    zombie * currZombie = zombies;
    while(currZombie != NULL){
        if(currZombie->zombieType != FIRSTNODEZOMBIE){
            DrawTexture(zombieTextures[currZombie->zombieType], currZombie->position.x, currZombie->position.y, WHITE);
            if(currZombie->health != currZombie->maxHealth){
                DrawRectangle(currZombie->position.x, currZombie->position.y - LEVEL1_HEALTHBAR_HEIGHT, currZombie->hitbox.width, LEVEL1_HEALTHBAR_HEIGHT, RED);
                DrawRectangle(currZombie->position.x, currZombie->position.y - LEVEL1_HEALTHBAR_HEIGHT, ((float)currZombie->health/currZombie->maxHealth)*currZombie->hitbox.width, LEVEL1_HEALTHBAR_HEIGHT, GREEN);
            }
            
            if(DEBUG == 1) DrawRectangleLines(currZombie->hitbox.x, currZombie->hitbox.y, currZombie->hitbox.width, currZombie->hitbox.height, RED);
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
            float radian = atanf(fabs((getMainPlayerCenter().y - currZombie->center.y)/(getMainPlayerCenter().x - currZombie->center.x)));
            float x = getMainPlayerCenter().x - currZombie->center.x > 0 ? 1.0 : -1.0;
            float y = getMainPlayerCenter().y - currZombie->center.y > 0 ? 1.0 : -1.0;
            currZombie->position.x += currZombie->speed*cos(radian)*dt*x;
            currZombie->position.y += currZombie->speed*sin(radian)*dt*y;
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

#endif