#ifndef INGAMEMENU_C
#define INGAMEMENU_C

#include "raylib.h"
#include "raygui.h"
#include "inGameMenu.h"
#include "mainGame.h"
#include "mainPlayer.h"
#include "gameMath.h"
#include <stdlib.h>
#include <stdio.h>

bool QuitInGameMenu, shouldDraw = false;
int *upgradeLevel;

void initInGameMenu(){
    free(upgradeLevel);
    upgradeLevel = calloc(UPGRADE_OPTIONS_COUNT + 1, sizeof(int));

    return;
}

void drawInGameMenu(){
    const int inGameMenuX = getScreenCoord().x + GetScreenWidth() - INGAMEMENU_WIDTH;
    const int inGameMenuY = getScreenCoord().y + (GetScreenHeight() - INGAMEMENU_HIGHT)/2;

    const int upgradeBarWidth = (INGAMEMENU_WIDTH - (UPGRADE_BAR_MAX-1 + 2)*UPGRADE_BAR_GAP_X)/UPGRADE_BAR_MAX;


    // Draw Window
    QuitInGameMenu = GuiWindowBox((Rectangle){inGameMenuX, inGameMenuY, INGAMEMENU_WIDTH, INGAMEMENU_HIGHT}, "InGame Menu");

    DrawText("Health", inGameMenuX + UPGRADE_GAP_X, inGameMenuY + UPGRADE_GAP_Y, UPGRADE_FONTSIZE, UPGRADE_COLOR);
    
    DrawText("Damage", inGameMenuX + UPGRADE_GAP_X, inGameMenuY + UPGRADE_GAP_Y*2, UPGRADE_FONTSIZE, UPGRADE_COLOR);
    
    DrawText("Attack Speed", inGameMenuX + UPGRADE_GAP_X, inGameMenuY + UPGRADE_GAP_Y*3, UPGRADE_FONTSIZE, UPGRADE_COLOR);
    
    DrawText("Walk Speed", inGameMenuX + UPGRADE_GAP_X, inGameMenuY + UPGRADE_GAP_Y*4, UPGRADE_FONTSIZE, UPGRADE_COLOR);

    for(int i=1; i<=UPGRADE_OPTIONS_COUNT; i++){
        // Draw Button
        if(GuiButtonPro((Rectangle){inGameMenuX + UPGRADE_BUTTON_GAP_X, inGameMenuY + UPGRADE_GAP_Y*i, UPGRADE_BUTTON_WIDTH, UPGRADE_BUTTON_HIGHT}, UPGRADE_BUTTON_TEXT, (Vector2){GetMousePosition().x + getScreenCoord().x, GetMousePosition().y + getScreenCoord().y})){
            if(getMainPlayerCoins() >= calUpgradeCost(i)){
                minusMainPlayerCoin(calUpgradeCost(i));
                upgradeLevel[i] += 1;
            }
        }
        // Draw Upgrade Level
        for(int j=1; j<=UPGRADE_BAR_MAX; j++){
            if(upgradeLevel[i] >= j){
                // Level Reached
                DrawRectangleRounded((Rectangle){inGameMenuX + UPGRADE_BAR_GAP_X + (UPGRADE_BAR_GAP_X + upgradeBarWidth)*(j-1), UPGRADE_BAR_OFFSET_Y + inGameMenuY + UPGRADE_BAR_GAP_Y*i, upgradeBarWidth, UPGRADE_BAR_HEIGHT}, 1.0f, 1, GREEN);
            }
            else{
                // Level Unreached
                DrawRectangleRounded((Rectangle){inGameMenuX + UPGRADE_BAR_GAP_X + (UPGRADE_BAR_GAP_X + upgradeBarWidth)*(j-1), UPGRADE_BAR_OFFSET_Y + inGameMenuY + UPGRADE_BAR_GAP_Y*i, upgradeBarWidth, UPGRADE_BAR_HEIGHT}, 1.0f, 1, GRAY);
            }
        }
        DrawCircle(GetMousePosition().x + getScreenCoord().x, GetMousePosition().y + getScreenCoord().y, 5, PINK);
    }

    if(QuitInGameMenu == true) shouldDraw = false;

    return;
}

void startDrawingInGameMenu(){
    shouldDraw = true;
    return;
}

void stopDrawingInGameMenu(){
    shouldDraw = false;
    return;
}

bool shouldDrawInGameMenu(){
    return shouldDraw;
}

#endif