#ifndef MAINPLAYER_C
#define MAINPLAYER_C

#include "raylib.h"
#include "mainPlayer.h"

#define PLAYER_START_X 0
#define PLAYER_START_Y 0

struct player mainPlayer;

void initMainPlayer(){
    mainPlayer.position = (Vector2){PLAYER_START_X, PLAYER_START_Y};
    mainPlayer.texture = LoadTexture("resources/target.png");
    mainPlayer.speed = 500.0;
    return;
}

void drawMainPlayer(){
    DrawTexture(mainPlayer.texture, (int)mainPlayer.position.x, (int)mainPlayer.position.y, WHITE);
    return;
}


// function for modifying and get player variables

Vector2 getMainPlayerLoc(){
    return mainPlayer.position;
}

void setMainPlayerLoc(Vector2 position){
    mainPlayer.position = position;
    return;
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

#endif