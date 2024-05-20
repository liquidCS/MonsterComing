#ifndef MENUPAGES_C
#define MENUPAGES_C

#include "raylib.h"
#include "raygui.h"

#define SETTINGSPAGE_WIDTH 500
#define SETTINGSPAGE_HEIGHT  500


bool QuitSettinsPage;
bool QuitCreditsPage;

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

void drawCreditsPage(){
    return;
}

bool shouldQuitCreditsPage(){
    return QuitCreditsPage;
}


#endif