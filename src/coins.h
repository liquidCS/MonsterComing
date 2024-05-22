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


void initCoins();
void spawnCoin(Vector2, int);
void drawCoins();

void coinPickDetect();

void deleteCoin(coin *, coin *);
void freeAllCoins();

#endif