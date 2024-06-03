#ifndef MAINGAME_H
#define MAINGAME_H

#include "raylib.h"

enum GameStatus{InGame};


void initMainGame();
void drawMainGame();
void endMainGame();

Texture2D getMainGameBackGround();
Vector2 getScreenCoord();

#endif