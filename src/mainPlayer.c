#ifndef MAINPLAYER_C
#define MAINPLAYER_C

#include "raylib.h"
#include "mainPlayer.h"
#include "basic.h"

#include "warrior.h"
#include "ninja.h"
#include "witch.h"

#define PLAYER_START_X 0
#define PLAYER_START_Y 0

struct player mainPlayer;
enum MAINPLAYERSTATES mainPlayerState;
enum MAINPLAYERFACING mainPlayerFacing;

// Init Main Player, Load in Character Texture 
void initMainPlayer(int SELECTEDCHARACTER){
    mainPlayer.position = (Vector2){PLAYER_START_X, PLAYER_START_Y};

    // Load Texture For Selected Character
    if(SELECTEDCHARACTER == WARRIOR){
        mainPlayer.texture = LoadTexture("resources/characters/warrior.png");
        initWarriorAttack();
    }else if(SELECTEDCHARACTER == NINJA){
        mainPlayer.texture = LoadTexture("resources/characters/ninja.png");
        initNinjaAttack();
    }else if(SELECTEDCHARACTER == WITCH){
        mainPlayer.texture = LoadTexture("resources/characters/witch.png");
        initWitchAttack();
    }
    mainPlayer.character = SELECTEDCHARACTER;

    // may be different with different character
    mainPlayer.animationChangeRate = 0.2;
    // Implying the Sizeof the Character
    mainPlayer.hitbox = (Rectangle) {0, 0, 64*1.2, 64*1.2}; 
    mainPlayer.center = (Vector2){PLAYER_START_X + mainPlayer.hitbox.width/2, PLAYER_START_Y + mainPlayer.hitbox.height/2};
    mainPlayer.speed = 1000.0;

    //Attack Damage
    mainPlayer.normalAttackDamage = 5;
    mainPlayer.normalAttackCool = 1;
    mainPlayer.normalAttackTimer = 0.0;

    mainPlayerState = STOP;
    mainPlayerFacing = SOUTH;
    
    return;
}

// Update Hitbox to Current Location
void updateMainPlayerHitbox2Loc(){
    mainPlayer.hitbox.x = mainPlayer.position.x;
    mainPlayer.hitbox.y = mainPlayer.position.y;

    return;
}

// Update Center For Zombie to Track
void updateCenter(){
    mainPlayer.center.x = mainPlayer.position.x + mainPlayer.hitbox.width/2;
    mainPlayer.center.y = mainPlayer.position.y + mainPlayer.hitbox.height/2;
}


// Draw Player With Animaiton
void drawMainPlayer(){
    // Calculate Time Passed
    static float accuTime = 0;
    accuTime += GetFrameTime();
    // Image Duration    
    static int i = 0; 

    // Draw Character
    Rectangle sourceTexture = {64*i, 64*mainPlayerFacing, 64, 64};
    Rectangle destPos = {(int)mainPlayer.position.x, (int)mainPlayer.position.y, mainPlayer.hitbox.width, mainPlayer.hitbox.height};
    DrawTexturePro(mainPlayer.texture, sourceTexture, destPos, (Vector2){0, 0}, 0, WHITE);

    // Animation: Change Texture 
    if(mainPlayerState == WALKING){
        if(accuTime >= mainPlayer.animationChangeRate){
            if(i == 3)
                i = 0;
            else
                i++;
            
            accuTime = 0;
        }
    }
    else if(mainPlayerState == STOP){
        // Reset Timer
        accuTime = 0;
    }
    
    return;
}


void timerUpdate(){

    // Normal Attack
    mainPlayer.normalAttackTimer += GetFrameTime();
    if(mainPlayer.normalAttackTimer > mainPlayer.normalAttackCool) mainPlayer.normalAttackTimer = mainPlayer.normalAttackCool;
}

void drawAttack(){
    if(mainPlayer.character == WARRIOR){
        drawWarriorNormalAnimation(false);
    }
    else if(mainPlayer.character == NINJA){
        drawNinjaNormalAnimation(false);
    }
    else if(mainPlayer.character == WITCH){
        drawWitchNormalAnimation(false);
    }
    return;
}


void normalAttack(){
    // Normal Attack Cool Down Detect
    if(mainPlayer.normalAttackTimer < getNormalAttackCool())
        return;
    else
        mainPlayer.normalAttackTimer = 0.0;

    if(mainPlayer.character == WARRIOR){
        warriorNormalAttack();
    }
    else if(mainPlayer.character == NINJA){
        ninjaNormalAttack();
    }
    else if(mainPlayer.character == WITCH){
        witchNormalAttack();
    }
}

// function for modifying and get player variables

Vector2 getMainPlayerLoc(){
    return mainPlayer.position;
}

void setMainPlayerLoc(Vector2 position){
    mainPlayer.position = position;
    return;
}

Vector2 getMainPlayerCenter(){
    return mainPlayer.center;
}

Rectangle getMainPlayerHitbox(){
    return mainPlayer.hitbox;
}

Texture2D getMainPlayerTexture(){
    return mainPlayer.texture;
}

float getMainPlayerSpeed(){
    return mainPlayer.speed;
}

void setMainPlayerSpeed(float newSpeed){
    mainPlayer.speed = newSpeed;
    return;
}

int getMainPlayerState(){
    return mainPlayerState;
}

void setMainPlayerState(int state){
    mainPlayerState = state;
}


int getMainPlayerFacing(){
    return mainPlayerFacing;
}

void setMainPlayerFacing(int facing){
    mainPlayerFacing = facing;
    return;   
}

int getNormalAttackDamage(){
    return mainPlayer.normalAttackDamage;
}

float getNormalAttackCool(){
    return mainPlayer.normalAttackCool;
}


void addMainPlayerXp(int xp){
    mainPlayer.xp += xp;
    return;
}


void addMainPlayerCoin(int coin){
    mainPlayer.coins += coin;
    return;
}

void minusMainPlayerCoin(int coin){
    mainPlayer.coins -= coin;
    return;
}

#endif