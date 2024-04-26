#ifndef MAINPLAYER_H
#define MAINPLAYER_H

#include "raylib.h"

struct player
{
    Vector2 position;    
    Texture2D texture;
    float speed; // pixel per sec (PPS)
};


void initMainPlayer();
void drawMainPlayer();


// variables
Vector2 getMainPlayerLoc();
void setMainPlayerLoc(Vector2);

Texture2D getMainPlayerTexture();

float getMainPlayerSpeed();
void setMainPlayerSpeed(float);

#endif