#ifndef MENUPAGES_C
#define MENUPAGES_C

#include "raylib.h"
#include "raygui.h"
#include "menuPages.h"
#include "saveHandler.h"
#include <stdio.h>
#include <stdlib.h>

bool QuitSettinsPage;
bool QuitStatisticPage;

void drawSettingsPage(){
    const int settingsWinX = GetScreenWidth()/2 - SETTINGSPAGE_WIDTH/2;
    const int settingsWinY = GetScreenHeight()/2 - SETTINGSPAGE_HEIGHT/2;
    // Settings Window
    QuitSettinsPage = GuiWindowBox((Rectangle){settingsWinX, settingsWinY, SETTINGSPAGE_WIDTH, SETTINGSPAGE_HEIGHT}, "Settings");

    return;
}

bool shouldQuitSettingsPage(){
    return QuitSettinsPage;
}

void drawStatisticPage(){
    const int statisticWinX = GetScreenWidth()/2 - STATISTICPAGE_WIDTH/2;
    const int statisticWinY = GetScreenHeight()/2 - STATISTICPAGE_HEIGHT/2;
    // Statistic Window
    QuitStatisticPage = GuiWindowBox((Rectangle){statisticWinX, statisticWinY, STATISTICPAGE_WIDTH, STATISTICPAGE_HEIGHT}, "Statistics");
    
    char temp[100];
    // Games Played Data
    sprintf(temp, "%d", getCurrStatistic(GAMESPLAYED));
    DrawText("Games Played:", statisticWinX + STATISTICPAGE_WALLGAP_TITLE, statisticWinY + STATISTICPAGE_ITEM_GAP, STATISTICPAGE_TITLE_FONTSIZE, DARKGREEN);
    DrawText(temp, statisticWinX + STATISTICPAGE_WALLGAP_DATA, statisticWinY + STATISTICPAGE_ITEM_GAP, STATISTICPAGE_DATA_FONTSIZE, DARKGREEN);
    // Zombies Killed Data
    sprintf(temp, "%d", getCurrStatistic(ZOMBIESKILLED));
    DrawText("Zombies Killed:", statisticWinX + STATISTICPAGE_WALLGAP_TITLE, statisticWinY + STATISTICPAGE_ITEM_GAP*2, STATISTICPAGE_TITLE_FONTSIZE, DARKGREEN);
    DrawText(temp, statisticWinX + STATISTICPAGE_WALLGAP_DATA, statisticWinY + STATISTICPAGE_ITEM_GAP*2, STATISTICPAGE_DATA_FONTSIZE, DARKGREEN);
    // Coins Earned Data
    sprintf(temp, "%d", getCurrStatistic(COINSEARNED));
    DrawText("Coins Earned:", statisticWinX + STATISTICPAGE_WALLGAP_TITLE, statisticWinY + STATISTICPAGE_ITEM_GAP*3, STATISTICPAGE_TITLE_FONTSIZE, DARKGREEN);
    DrawText(temp, statisticWinX + STATISTICPAGE_WALLGAP_DATA, statisticWinY + STATISTICPAGE_ITEM_GAP*3, STATISTICPAGE_DATA_FONTSIZE, DARKGREEN);
    // Damaged Made Data
    sprintf(temp, "%d", getCurrStatistic(DAMAGEDMADE));
    DrawText("Damage Made:", statisticWinX + STATISTICPAGE_WALLGAP_TITLE, statisticWinY + STATISTICPAGE_ITEM_GAP*4, STATISTICPAGE_TITLE_FONTSIZE, DARKGREEN);
    DrawText(temp, statisticWinX + STATISTICPAGE_WALLGAP_DATA, statisticWinY + STATISTICPAGE_ITEM_GAP*4, STATISTICPAGE_DATA_FONTSIZE, DARKGREEN);
    // Losted Health Data
    sprintf(temp, "%d", getCurrStatistic(LOSTEDHEALTH));
    DrawText("Losted Health:", statisticWinX + STATISTICPAGE_WALLGAP_TITLE, statisticWinY + STATISTICPAGE_ITEM_GAP*5, STATISTICPAGE_TITLE_FONTSIZE, DARKGREEN);
    DrawText(temp, statisticWinX + STATISTICPAGE_WALLGAP_DATA, statisticWinY + STATISTICPAGE_ITEM_GAP*5, STATISTICPAGE_DATA_FONTSIZE, DARKGREEN);
        


    return;
}

bool shouldQuitStatisticPage(){
    return QuitStatisticPage;
}


#endif