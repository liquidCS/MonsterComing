#ifndef COINS_C
#define COINS_C

#include "coins.h"
#include "mainPlayer.h"
#include "saveHandler.h"
#include <stdlib.h>
#include <stdio.h>

coin *coins, *lastCoin;
Texture2D coinTexture;
Sound pickUPCoinSound;

void initCoins(){
    coins = (coin *)malloc(sizeof(coin));
    (*coins) = (coin){.value = -1, .nextCoin = NULL};
    lastCoin = coins;

    // Load Coin Music
    pickUPCoinSound = LoadSound("resources/soundEffect/coin.wav");

    // Load Coin Texture
    coinTexture = LoadTexture("resources/spinningCoin.png");
    return;
}

void spawnCoin(Vector2 position, int value){
    coin *newCoin = (coin *)malloc(sizeof(coin));
    lastCoin->nextCoin = newCoin;
    lastCoin = lastCoin->nextCoin;
    
    
    lastCoin->position = (Vector2){position.x + rand()%41-20, position.y + rand()%41-20};
    lastCoin->value = value;
    lastCoin->nextCoin = NULL;
    
    return;
}

void drawCoins(){
    static float currFrameTime = 0;
    static int imageState = 0;
    coin *currCoin = coins;
    while(currCoin != NULL){
        if(currCoin->value != -1){
            Rectangle source = {COIN_TEXTURE_WIDTH*imageState, 0, COIN_TEXTURE_WIDTH, COIN_TEXTURE_HEIGHT};
            Rectangle dest = {currCoin->position.x-COIN_TEXTURE_WIDTH/2, currCoin->position.y-COIN_TEXTURE_HEIGHT/2, COIN_TEXTURE_WIDTH, COIN_TEXTURE_HEIGHT};
            DrawTexturePro(coinTexture, source, dest, (Vector2){0, 0}, 0, WHITE);
        }
        currCoin = currCoin->nextCoin;
    }
    if(currFrameTime >= ANIMATION_FRAME_TIME){
        currFrameTime = 0.0;
        imageState = imageState == 4 ? 0 : imageState+1;
    }
    else{
        currFrameTime += GetFrameTime();
    }
    return;
}


void coinPickDetect(){
    coin *currCoin = coins, *prevCoin, *nextCoin;
    while(currCoin != NULL){
        if(currCoin->value != -1){
            if(CheckCollisionRecs((Rectangle){currCoin->position.x, currCoin->position.y, COIN_TEXTURE_WIDTH, COIN_TEXTURE_HEIGHT}, getMainPlayerHitbox())){
                // Add to statistic
                writeCurrStatistic(COINSEARNED, currCoin->value);                
                // Play Coin Sound
                PlaySound(pickUPCoinSound);
                // Add to Current Coin Count
                addMainPlayerCoin(currCoin->value);
                // Delete Coin
                nextCoin = currCoin->nextCoin;
                lastCoin = prevCoin;
                deleteCoin(prevCoin, currCoin);
                currCoin = nextCoin;
            }
            else{
                prevCoin = currCoin;
                currCoin = currCoin->nextCoin;
            }
        }
        else{
            prevCoin = currCoin;
            currCoin = currCoin->nextCoin;   
        }
    }
    return;
}


coin *getCoins(){
    return coins;
}

void deleteCoin(coin *prevCoin, coin *targetCoin){
    prevCoin->nextCoin = targetCoin->nextCoin;
    free(targetCoin);
    return;
}

void freeAllCoins(){
    coin *currCoin, *nextCoin;
    while(currCoin != NULL){
        nextCoin = currCoin->nextCoin;
        free(currCoin);
        currCoin = nextCoin;
    }
    free(currCoin);
    return;
}

#endif