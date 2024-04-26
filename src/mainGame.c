#ifndef MAINGAME_C
#define MAINGAME_C

#include "raylib.h"
#include "mainPlayer.h"
#include "inputHandler.h"
#include <stdio.h>


Texture2D backGround;
Camera2D mainCam;


// Load Texture, Sound and Initialize Valuables
void initMainGame(){
    // Load Background
    backGround = LoadTexture("resources/tempMap.png");

    // Initialize Camera
    mainCam.offset = (Vector2){0, 0};
    mainCam.rotation = 0;
    mainCam.target = (Vector2){0, 0}; // *temporary: need to grab from player location
    mainCam.zoom = 1.0;

    return;
}

// Offset Camera So That It Won't Render Out Of Boundry
void cameraRenderFix(){
    mainCam.offset.x = GetScreenWidth()/2 - getMainPlayerTexture().width/2;
    mainCam.offset.y = GetScreenHeight()/2 - getMainPlayerTexture().height/2;
}



// Main Game 
void drawMainGame(){

    // Handle Input
    inputHandle();

    // Render Using Custom Camera
    mainCam.target = (Vector2){(int)getMainPlayerLoc().x, (int)getMainPlayerLoc().y};
    cameraRenderFix();
    BeginMode2D(mainCam);

    // Draw Back Ground
    ClearBackground(WHITE);
    DrawTexture(backGround, 0, 0, WHITE);

    // Draw Main Player
    drawMainPlayer();

    return;
}

// Unload Texture, Sound... from Memory
void endMainGame(){
    UnloadTexture(backGround);
    return;
}


// Get Backgroud Texture (should be a single c file if there is several different maps)
Texture2D getMainGameBackGround(){
    return backGround;
}

#endif