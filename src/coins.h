#ifndef COINS_H
#define COINS_H

#include "raylib.h"

typedef struct coinNode{
    int value;
    Vector2 position;
    struct coinNode *nextCoin;
} coin;

#define ANIMATION_FRAME_TIME 0.1f
#define COIN_TEXTURE_HEIGHT 16
#define COIN_TEXTURE_WIDTH 16


void initCoins(); // load settings and textures
void spawnCoin(Vector2, int); // new coin add
void drawCoins(); // draw all coins

coin *getCoins();

void coinPickDetect(); // detect if player pick up coins

void deleteCoin(coin *, coin *); // delete coin 
void freeAllCoins(); // call when game closed

#endif