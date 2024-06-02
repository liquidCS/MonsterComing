#ifndef MAINGAMEGUI_H
#define MAINGAMEGUI_H

#include "raygui.h"
#include "mainPlayer.h"
#include "mainGame.h"
#include "stdio.h"
#include "stdlib.h"

// Gap Between Different Element
#define UI_GAP 10

// Coin
#define COIN_UI_FONT_SIZE 20
#define COIN_UI_HIGHT 130

// Normal Attack Cool Down
#define N_ATTACK_UI_FONTSIZE 20
#define N_ATTACK_UI_HIGHT 25
#define N_ATTACK_UI_WIDTH 500

// Special Attack Timer
#define S_ATTACK_UI_FONTSIZE 20
#define S_ATTACK_UI_HIGHT 25
#define S_ATTACK_UI_WIDTH 500

// Health
#define HEALTH_UI_FONTSIZE 20
#define HEALTH_UI_X2BOTTOM 10
#define HEALTH_UI_HIGHT 25
#define HEALTH_UI_WIDTH 500

// Waves Information
#define WAVES_FONTSIZE 20
#define MEXTWAVE_TEXT_LENGTH 200
#define WAVE_GAP2SCREENTOP 5
#define WAVE_GAP 25

// MINI MAP
#define MINIMAP_WIDTH 240
#define MINIMAP_HEIGHT 135




void initGameGUI();
void drawGUI();
Vector2 getMiniMapLoc();


#endif