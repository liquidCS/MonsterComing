#ifndef MAINGAMEGUI_C
#define MAINGAMEGUI_C

#include "string.h"
#include "mainGame.h"
#include "mainGameGUI.h"
#include <stdlib.h>


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
    const int N_ATTACK_UI_Y = getScreenCoord().y + GetScreenHeight() - (HEALTH_UI_X2BOTTOM + HEALTH_UI_HIGHT) - UI_GAP - N_ATTACK_UI_HIGHT;
    const int N_ATTACK_UI_CURRENT_X = N_ATTACK_UI_WIDTH*(getNormalAttackTimer()/getNormalAttackCool());    

    char N_ATTACK_UI_TEXT[20];
    sprintf(N_ATTACK_UI_TEXT, "%f", getNormalAttackCool()-getNormalAttackTimer());
    const int N_ATTACK_UI_TEXT_WIDTH = MeasureText(N_ATTACK_UI_TEXT, N_ATTACK_UI_FONTSIZE);
    const int N_ATTACK_UI_TEXT_X = getScreenCoord().x + GetScreenWidth()/2 - N_ATTACK_UI_TEXT_WIDTH/2;
    const int N_ATTACK_UI_TEXT_Y = N_ATTACK_UI_Y + (N_ATTACK_UI_HIGHT-N_ATTACK_UI_FONTSIZE)/2;

    DrawRectangle(N_ATTACK_UI_X, N_ATTACK_UI_Y, N_ATTACK_UI_WIDTH, N_ATTACK_UI_HIGHT, BLACK);
    DrawRectangle(N_ATTACK_UI_X, N_ATTACK_UI_Y, N_ATTACK_UI_CURRENT_X, N_ATTACK_UI_HIGHT, GRAY);
    DrawText(N_ATTACK_UI_TEXT, N_ATTACK_UI_TEXT_X, N_ATTACK_UI_TEXT_Y, N_ATTACK_UI_FONTSIZE, DARKGRAY);

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

    return;
}   

#endif
