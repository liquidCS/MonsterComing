#ifndef MAINGAMEGUI_C
#define MAINGAMEGUI_C

#include "string.h"
#include "mainGame.h"
#include "mainGameGUI.h"
#include "basic.h"
#include "coins.h"
#include "zombies.h"
#include "zombieWaves.h"
#include <stdlib.h>

int MINIMAP_X, MINIMAP_Y;

// Init settings
void initGameGUI(){
    MINIMAP_X = getScreenCoord().x;
    MINIMAP_Y = getScreenCoord().y + GetScreenHeight() - MINIMAP_HEIGHT;
    return;
}


void drawGUI(){

    // Draw Coins Count
    char charCoins[10], coinUI[20] = "Coins: "; // generate words
    itoa(getMainPlayerCoins(), charCoins, 10);
    strcat(coinUI, charCoins);
    const int COIN_UI_WIDTH = MeasureText(coinUI, COIN_UI_FONT_SIZE);
    
    const int COIN_UI_X = getScreenCoord().x + GetScreenWidth()/2 - COIN_UI_WIDTH/2; // calculate position
    const int COIN_UI_Y = getScreenCoord().y + GetScreenHeight() - COIN_UI_HIGHT; 

    DrawText(coinUI, COIN_UI_X , COIN_UI_Y, COIN_UI_FONT_SIZE, GOLD);
    
    // Draw Normal Attack Cool Down
    const int N_ATTACK_UI_X = getScreenCoord().x + GetScreenWidth()/2 - N_ATTACK_UI_WIDTH/2;
    const int N_ATTACK_UI_Y = getScreenCoord().y + GetScreenHeight() - (HEALTH_UI_X2BOTTOM + HEALTH_UI_HIGHT*2) - UI_GAP*2 - N_ATTACK_UI_HIGHT;
    const int N_ATTACK_UI_CURRENT_X = N_ATTACK_UI_WIDTH*(getNormalAttackTimer()/getNormalAttackCool());    

    char N_ATTACK_UI_TEXT[20];
    sprintf(N_ATTACK_UI_TEXT, "%f", getNormalAttackCool()-getNormalAttackTimer());
    const int N_ATTACK_UI_TEXT_WIDTH = MeasureText(N_ATTACK_UI_TEXT, N_ATTACK_UI_FONTSIZE);
    const int N_ATTACK_UI_TEXT_X = getScreenCoord().x + GetScreenWidth()/2 - N_ATTACK_UI_TEXT_WIDTH/2;
    const int N_ATTACK_UI_TEXT_Y = N_ATTACK_UI_Y + (N_ATTACK_UI_HIGHT-N_ATTACK_UI_FONTSIZE)/2;

    DrawRectangle(N_ATTACK_UI_X, N_ATTACK_UI_Y, N_ATTACK_UI_WIDTH, N_ATTACK_UI_HIGHT, BLACK);
    DrawRectangle(N_ATTACK_UI_X, N_ATTACK_UI_Y, N_ATTACK_UI_CURRENT_X, N_ATTACK_UI_HIGHT, GRAY);
    DrawText(N_ATTACK_UI_TEXT, N_ATTACK_UI_TEXT_X, N_ATTACK_UI_TEXT_Y, N_ATTACK_UI_FONTSIZE, DARKGRAY);

    // Draw Special Attack Timer
    const int S_ATTACK_UI_X = getScreenCoord().x + GetScreenWidth()/2 - S_ATTACK_UI_WIDTH/2;
    const int S_ATTACK_UI_Y = getScreenCoord().y + GetScreenHeight() - (HEALTH_UI_X2BOTTOM + HEALTH_UI_HIGHT) - UI_GAP - S_ATTACK_UI_HIGHT;
    const int S_ATTACK_UI_CURRENT_X = S_ATTACK_UI_WIDTH*(getSpecialAttackTimer()/getSpecialAttackCool());    

    char S_ATTACK_UI_TEXT[20];
    sprintf(S_ATTACK_UI_TEXT, "%f", getSpecialAttackCool()-getSpecialAttackTimer());
    const int S_ATTACK_UI_TEXT_WIDTH = MeasureText(S_ATTACK_UI_TEXT, S_ATTACK_UI_FONTSIZE);
    const int S_ATTACK_UI_TEXT_X = getScreenCoord().x + GetScreenWidth()/2 - S_ATTACK_UI_TEXT_WIDTH/2;
    const int S_ATTACK_UI_TEXT_Y = S_ATTACK_UI_Y + (S_ATTACK_UI_HIGHT-S_ATTACK_UI_FONTSIZE)/2;

    DrawRectangle(S_ATTACK_UI_X, S_ATTACK_UI_Y, S_ATTACK_UI_WIDTH, S_ATTACK_UI_HIGHT, BLACK);
    DrawRectangle(S_ATTACK_UI_X, S_ATTACK_UI_Y, S_ATTACK_UI_CURRENT_X, S_ATTACK_UI_HIGHT, ORANGE);
    DrawText(S_ATTACK_UI_TEXT, S_ATTACK_UI_TEXT_X, S_ATTACK_UI_TEXT_Y, S_ATTACK_UI_FONTSIZE, DARKGRAY);
    
    
    
    // Draw Health
    const int HEALTH_UI_X = getScreenCoord().x + GetScreenWidth()/2 - HEALTH_UI_WIDTH/2; // Health UI Location
    const int HEALTH_UI_Y = getScreenCoord().y + GetScreenHeight() - (HEALTH_UI_X2BOTTOM + HEALTH_UI_HIGHT);
    const int HEALTH_UI_CURRENT_X = HEALTH_UI_WIDTH*(getMainPlayerCurrHealth()/getMainPlayerMaxHealth());

    char currTextHealth[20], maxTextHealth[20], healthUIText[41] = ""; // Health UI Text
    itoa(getMainPlayerCurrHealth(), currTextHealth, 10);
    itoa(getMainPlayerMaxHealth(), maxTextHealth, 10);

    strcat(healthUIText, currTextHealth); // construct health bar text
    strcat(healthUIText, "/");
    strcat(healthUIText, maxTextHealth);
    const int HEALTH_UI_TEXT_WIDTH = MeasureText(healthUIText, HEALTH_UI_FONTSIZE);
    const int HEALTH_UI_TEXT_X = getScreenCoord().x + GetScreenWidth()/2 - HEALTH_UI_TEXT_WIDTH/2;
    const int HEALTH_UI_TEXT_Y = HEALTH_UI_Y + (HEALTH_UI_HIGHT - HEALTH_UI_FONTSIZE)/2;

    DrawRectangle(HEALTH_UI_X, HEALTH_UI_Y, HEALTH_UI_WIDTH, HEALTH_UI_HIGHT, RED);
    DrawRectangle(HEALTH_UI_X, HEALTH_UI_Y, HEALTH_UI_CURRENT_X, HEALTH_UI_HIGHT, GREEN);
    DrawText(healthUIText, HEALTH_UI_TEXT_X, HEALTH_UI_TEXT_Y, HEALTH_UI_FONTSIZE, BLACK);  


    // Draw Wave Information
    int currWaveLength = GetScreenWidth()*((WAVETIME - getNextWaveTime()) / WAVETIME);
    DrawLineEx(getScreenCoord(), (Vector2){getScreenCoord().x + currWaveLength, getScreenCoord().y}, 10, RED);
    
    char NEXTWAVE_TIME[20];
    sprintf(NEXTWAVE_TIME, "Next Wave: %.1fs", getNextWaveTime());
    DrawText(NEXTWAVE_TIME, getScreenCoord().x + GetScreenWidth()/2 - MEXTWAVE_TEXT_LENGTH/2, getScreenCoord().y + WAVE_GAP2SCREENTOP, WAVES_FONTSIZE, RED);

    char CURRWAVE_NUM[20];
    sprintf(CURRWAVE_NUM, "Curr Wave: %d", getCurrWave());
    DrawText(CURRWAVE_NUM, getScreenCoord().x + GetScreenWidth()/2 - MEXTWAVE_TEXT_LENGTH/2, getScreenCoord().y + WAVE_GAP2SCREENTOP + WAVE_GAP, WAVES_FONTSIZE, DARKGREEN);

    // MINI MAP bottom left on screen
    MINIMAP_X = getScreenCoord().x;
    MINIMAP_Y = getScreenCoord().y + GetScreenHeight() - MINIMAP_HEIGHT;
    DrawTexturePro(getMainGameBackGround(), (Rectangle){0,0,getMainGameBackGround().width, getMainGameBackGround().height}, (Rectangle){MINIMAP_X, MINIMAP_Y, MINIMAP_WIDTH, MINIMAP_HEIGHT}, (Vector2){0, 0}, 0.0f, WHITE);
    DrawLine(MINIMAP_X, MINIMAP_Y, MINIMAP_X + MINIMAP_WIDTH, MINIMAP_Y, BLACK);
    DrawLine(MINIMAP_X + MINIMAP_WIDTH, MINIMAP_Y, MINIMAP_X + MINIMAP_WIDTH, MINIMAP_Y + MINIMAP_HEIGHT, BLACK);
    
    // Draw Loots on MINI MAP
    coin *currCoin = getCoins();
    while(currCoin != NULL){
        if(currCoin->value != -1){
            // Draw Zombie On Mini Map
            DrawCircle(MINIMAP_X + MINIMAP_WIDTH*(currCoin->position.x/getMainGameBackGround().width), MINIMAP_Y + MINIMAP_HEIGHT*(currCoin->position.y/getMainGameBackGround().height), 1, GREEN);
        }
        // Next Zombie Node
        currCoin = currCoin->nextCoin;
    }
    
    // Draw Zombie On MINI MAP
    zombie * currZombie = getZombies();
    while(currZombie != NULL){
        if(currZombie->zombieType != FIRSTNODEZOMBIE){
            // Draw Zombie On Mini Map
            DrawCircle(MINIMAP_X + MINIMAP_WIDTH*(currZombie->position.x/getMainGameBackGround().width), MINIMAP_Y + MINIMAP_HEIGHT*(currZombie->position.y/getMainGameBackGround().height), 2, RED);
        }
        // Next Zombie Node
        currZombie = currZombie->nextZombie;
    }
    // Draw player On mini map
    DrawCircle(MINIMAP_X + MINIMAP_WIDTH*(getMainPlayerCenter().x/getMainGameBackGround().width), MINIMAP_Y + MINIMAP_HEIGHT*(getMainPlayerCenter().y/getMainGameBackGround().height), 3, BLUE);


    #if DEBUG == 1
        char FPS[5];
        itoa(GetFPS(), FPS, 10);
        DrawText(FPS, getScreenCoord().x + 5, getScreenCoord().y + 5, 30, RED);
    #endif

    return;
}   



Vector2 getMiniMapLoc(){
    return (Vector2){MINIMAP_X, MINIMAP_Y};
}
#endif
