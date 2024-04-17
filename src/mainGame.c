#ifndef MAINGAME_C
#define MAINGAME_C

#include "raylib.h"


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

// Main Game 
void drawMainGame(){

    // Render Using Custom Camera
    BeginMode2D(mainCam);

    // Draw Back Ground
    DrawTexture(backGround, 0, 0, WHITE);

    return;
}

// Unload Texture, Sound... from Memory
void endMainGame(){
    UnloadTexture(backGround);
    return;
}

#endif