#ifndef WARRIOR_C
#define WARRIOR_C

#include "warrior.h"
#include "raylib.h"
#include "zombies.h"
#include "mainPlayer.h"
#include "basic.h"
#include "saveHandler.h"
#include <stdlib.h>
#include <stdio.h>


Vector2 normalAnimationCenter, specialAnimationCenter;
Texture2D normalAttackTexture, specialAnimationTexture;
Sound swordSound;

void initWarriorAttack(){
    normalAttackTexture = LoadTexture("resources/characters/warriorAttackEffect.png");
    swordSound = LoadSound("resources/soundEffect/swordSound.wav");
}

void warriorNormalAttack(){
    zombie *currZombie = getZombies();
    enum MAINPLAYERFACING facing = getMainPlayerFacing();
    Rectangle attackRange;

    // Play Sound Effect
    if(!IsSoundPlaying(swordSound))
        PlaySound(swordSound);

    // Generate Attack Range
    if(facing == NORTH){
        attackRange = (Rectangle){getMainPlayerCenter().x - NORMAL_ATTACK_WIDTH/2, getMainPlayerCenter().y - NORMAL_ATTACK_HEIGHT, NORMAL_ATTACK_WIDTH, NORMAL_ATTACK_HEIGHT};
    }
    else if(facing == WEST){
        attackRange = (Rectangle){getMainPlayerCenter().x - NORMAL_ATTACK_WIDTH, getMainPlayerCenter().y - NORMAL_ATTACK_HEIGHT/2, NORMAL_ATTACK_HEIGHT, NORMAL_ATTACK_WIDTH};
    }
    else if(facing == EAST){
        attackRange = (Rectangle){getMainPlayerCenter().x, getMainPlayerCenter().y - NORMAL_ATTACK_HEIGHT/2, NORMAL_ATTACK_HEIGHT, NORMAL_ATTACK_WIDTH};
    }
    else if(facing == SOUTH){
        attackRange = (Rectangle){getMainPlayerCenter().x - NORMAL_ATTACK_WIDTH/2, getMainPlayerCenter().y, NORMAL_ATTACK_WIDTH, NORMAL_ATTACK_HEIGHT};
    }

    // For Attack Animation Position
    normalAnimationCenter = (Vector2){attackRange.x + attackRange.width/2, attackRange.y + attackRange.height/2};
    drawWarriorNormalAnimation(true);

    if(DEBUG == 1)
        DrawRectangleLines((int)attackRange.x, (int)attackRange.y, (int)attackRange.width, (int)attackRange.height, RED);
    
    // Check if Zombie is in Attack Range
    while(currZombie != NULL){
        if(currZombie->zombieType != FIRSTNODEZOMBIE){
            if(CheckCollisionRecs(currZombie->hitbox, attackRange)){
                int damage = getNormalAttackDamage();
                currZombie->health -= damage;
                // Draw Damage Value (with critical damage calculate)
                if((rand()%100+1) <= getCriticalHitPercentage()*100){
                    // Critical Hit
                    addZombieDamageAnimation(currZombie, damage*2, CRITICAL);
                    // Add to Statistic
                    writeCurrStatistic(DAMAGEDMADE, damage*2);
                }else{
                    // Normal Hit
                    addZombieDamageAnimation(currZombie, damage, NORMAL);
                    // Add to Statistic
                    writeCurrStatistic(DAMAGEDMADE, damage);
                }
            }
        }
        currZombie = currZombie->nextZombie;
    }

    return;
}

// Draw Normal Attack Animation
void drawWarriorNormalAnimation(bool newAttack){
    static float currTime = 0.0;
    static int i = 0; // curr image count
    currTime += GetFrameTime();
    if(currTime >= ANIMATION_TIME) currTime = ANIMATION_TIME;

    if(newAttack){
        currTime = 0.0; // if there is a new attack reset rimer
        i = 0;
    }
    if(currTime < ANIMATION_TIME){
        #if DEBUG == 1
            DrawCircleLines(normalAnimationCenter.x, normalAnimationCenter.y, 30.0, RED);
        #endif 

        if(currTime >= (ANIMATION_TIME/ANIMATION_FRAMES)*i){ // calcuation with frame to draw
            i++; 
            i = i >= ANIMATION_FRAMES ? 0 : i;
        }
        Rectangle Source = {ANIMATION_SIZE*i, getMainPlayerFacing()*ANIMATION_SIZE, ANIMATION_SIZE, ANIMATION_SIZE};
        Rectangle Dest = {normalAnimationCenter.x - ANIMATION_SIZE/2, normalAnimationCenter.y - ANIMATION_SIZE/2, ANIMATION_SIZE*1.5, ANIMATION_SIZE*1.5};
        DrawTexturePro(normalAttackTexture, Source, Dest, (Vector2){0, 0}, 0, WHITE);  
        // DrawTexture(normalAttackTexture, normalAnimationCenter.x - normalAttackTexture.width/2, normalAnimationCenter.y - normalAttackTexture.height/2, WHITE );
    }

    return;
}



void warriorSpecialAttack(){
    zombie *currZombie = getZombies();
    enum MAINPLAYERFACING facing = getMainPlayerFacing();
    Rectangle attackRange;

    // Generate Attack Range
    if(facing == NORTH){
        attackRange = (Rectangle){getMainPlayerCenter().x - SPECIAL_ATTACK_HEIGHT/2, getMainPlayerCenter().y - SPECIAL_ATTACK_WIDTH, SPECIAL_ATTACK_HEIGHT, SPECIAL_ATTACK_WIDTH};
        setMainPlayerLoc((Vector2){getMainPlayerLoc().x, getMainPlayerLoc().y - SPECIAL_ATTACK_WIDTH});
    }
    else if(facing == WEST){
        attackRange = (Rectangle){getMainPlayerCenter().x - SPECIAL_ATTACK_WIDTH, getMainPlayerCenter().y - SPECIAL_ATTACK_HEIGHT/2, SPECIAL_ATTACK_WIDTH, SPECIAL_ATTACK_HEIGHT};
        setMainPlayerLoc((Vector2){getMainPlayerLoc().x - SPECIAL_ATTACK_WIDTH, getMainPlayerLoc().y});
    }
    else if(facing == EAST){
        attackRange = (Rectangle){getMainPlayerCenter().x, getMainPlayerCenter().y - SPECIAL_ATTACK_HEIGHT/2, SPECIAL_ATTACK_WIDTH, SPECIAL_ATTACK_HEIGHT};
        setMainPlayerLoc((Vector2){getMainPlayerLoc().x + SPECIAL_ATTACK_WIDTH, getMainPlayerLoc().y});
    }
    else if(facing == SOUTH){
        attackRange = (Rectangle){getMainPlayerCenter().x - SPECIAL_ATTACK_HEIGHT/2, getMainPlayerCenter().y, SPECIAL_ATTACK_HEIGHT, SPECIAL_ATTACK_WIDTH};
        setMainPlayerLoc((Vector2){getMainPlayerLoc().x, getMainPlayerLoc().y + SPECIAL_ATTACK_WIDTH});
    }

    // For Attack Animation Position
    specialAnimationCenter = (Vector2){attackRange.x + attackRange.width/2, attackRange.y + attackRange.height/2};
    drawWarriorSpecialAnimation(true);

    if(DEBUG == 1)
        DrawRectangleLines((int)attackRange.x, (int)attackRange.y, (int)attackRange.width, (int)attackRange.height, RED);
    
    // Check if Zombie is in Attack Range
    while(currZombie != NULL){
        if(currZombie->zombieType != FIRSTNODEZOMBIE){
            if(CheckCollisionRecs(currZombie->hitbox, attackRange)){
                int damage = getSpecialAttackDamage();
                currZombie->health -= damage;
                // Draw Damage Value (with critical damage calculate)
                addZombieDamageAnimation(currZombie, damage, NORMAL);
                // Add to Statistic
                writeCurrStatistic(DAMAGEDMADE, damage);
            }
        }
        currZombie = currZombie->nextZombie;
    }    

    return;
}


void drawWarriorSpecialAnimation(bool newAttack){
    return;
}




#endif
