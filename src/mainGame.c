#ifndef MAINGAME_C
#define MAINGAME_C

#include "raylib.h"
#include "mainPlayer.h"
#include "inputHandler.h"
#include "basic.h"
#include "zombies.h"
#include "coins.h"
#include "mainGameGUI.h"
#include <stdio.h>


Texture2D backGround;
Camera2D mainCam;
Vector2 screenCoord;

// Load Texture, Sound and Initialize Valuables
void initMainGame(){
    // Load Background
    backGround = LoadTexture("resources/tempMap.png");

    // Initialize Camera
    mainCam.offset = (Vector2){0, 0};
    mainCam.rotation = 0;
    mainCam.target = (Vector2){0, 0}; // *temporary: need to grab from player location
    mainCam.zoom = 1.0;

    initCoins();
    initZombies();

    return;
}

// Offset Camera So That It Won't Render Out Of Boundry
void _cameraRenderFix(){
    // x-axis
    if(mainCam.target.x < GetScreenWidth()/2)
        mainCam.offset.x = mainCam.target.x;
    else if(mainCam.target.x > backGround.width - GetScreenWidth()/2 - getMainPlayerHitbox().width)
        mainCam.offset.x = GetScreenWidth() - (backGround.width - mainCam.target.x);
    else
        mainCam.offset.x = GetScreenWidth()/2 - getMainPlayerHitbox().width/2;


    // y-axis
    if(mainCam.target.y < GetScreenHeight()/2)
        mainCam.offset.y = mainCam.target.y;
    else if(mainCam.target.y > backGround.height - GetScreenHeight()/2 - getMainPlayerHitbox().height)
        mainCam.offset.y = GetScreenHeight() - (backGround.height - mainCam.target.y);
    else
        mainCam.offset.y = GetScreenHeight()/2 - getMainPlayerHitbox().height/2;


    screenCoord.x = mainCam.target.x - mainCam.offset.x;
    screenCoord.y = mainCam.target.y - mainCam.offset.y;
    return;
}

// Main Game
void drawMainGame(){
    // Render Using Custom Camera
    mainCam.target = (Vector2){(int)getMainPlayerLoc().x, (int)getMainPlayerLoc().y};
    _cameraRenderFix();
    BeginMode2D(mainCam);

    // Cool Down, Animation...
    timerUpdate();

    // Draw Back Ground
    ClearBackground(WHITE);
    DrawTexture(backGround, 0, 0, WHITE);

    // Update Zombie Movement
    zombieMovement();

    // Handle Input
    inputHandle();
    otherKeyDetection();

    // Check Zombie 
    zombieCheck();
    
    // Detect If coin is Pick By Player
    coinPickDetect();

    // Draw loots
    drawCoins();

    // Draw All Zombies
    drawZombies();
    drawZombieDamageValue();

    // Draw Main Player
    drawMainPlayer();

    // Draw Attack Animation
    drawAttack();

    // Draw GUI
    drawGUI();

    // Debug
    #if DEBUG == 1
        DrawRectangleLines(getMainPlayerHitbox().x, getMainPlayerHitbox().y, getMainPlayerHitbox().width, getMainPlayerHitbox().height, RED);
    #endif

    return;
}

// Unload Texture, Sound... from Memory
void endMainGame(){
    UnloadTexture(backGround);
    freeAllZombie();
    return;
}


// Get Backgroud Texture (should be a single c file if there is several different maps)
Texture2D getMainGameBackGround(){
    return backGround;
}


Vector2 getScreenCoord(){
    return screenCoord;
}

#endif
