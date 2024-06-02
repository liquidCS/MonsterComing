#ifndef INPUTHANDLER_C
#define INPUTHANDLER_C

#include <math.h>
#include <stdio.h>
#include "raylib.h"
#include "mainPlayer.h"
#include "mainGame.h"
#include "zombies.h"
#include "inGameMenu.h"
#include "basic.h"

#define FOURTYFIVE_DEGREE 0.785398163397448309

void inputHandle(){
    Vector2 nowMainPlayerPos = getMainPlayerLoc();
    float dt = GetFrameTime();
    double degree;
    bool movementDetect = false;

    // Check if Player is Going For Two Direction at the Same Time
    if((IsKeyDown(KEY_UP) || IsKeyDown(KEY_DOWN) && (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_RIGHT))))
        degree = FOURTYFIVE_DEGREE;
    else
        degree = 0;

    if(IsKeyDown(KEY_LEFT)){
        setMainPlayerFacing(WEST);
        setMainPlayerState(WALKING);
        nowMainPlayerPos.x -= getMainPlayerSpeed()*dt*cos(degree);
        movementDetect = true;
    }
    if(IsKeyDown(KEY_RIGHT)){
        setMainPlayerFacing(EAST);
        setMainPlayerState(WALKING);
        nowMainPlayerPos.x += getMainPlayerSpeed()*dt*cos(degree);
        movementDetect = true;
    }
    if(IsKeyDown(KEY_UP)){
        setMainPlayerFacing(NORTH);
        setMainPlayerState(WALKING);
        nowMainPlayerPos.y -= getMainPlayerSpeed()*dt*cos(degree);
        movementDetect = true;
    }
    if(IsKeyDown(KEY_DOWN)){
        setMainPlayerFacing(SOUTH);
        setMainPlayerState(WALKING);
        nowMainPlayerPos.y += getMainPlayerSpeed()*dt*cos(degree);
        movementDetect = true;
    }
    if(movementDetect == false)
        setMainPlayerState(STOP);

    // Postion Check
    // The Player's Cordinate is On the Top Right Corner of Player Texture so When Checking for Right and Left Bound
    // BackGround.Width/Height - Player.Width/Height is necessary
    nowMainPlayerPos.x = nowMainPlayerPos.x < 0 ? 0 : nowMainPlayerPos.x;
    nowMainPlayerPos.y = nowMainPlayerPos.y < 0 ? 0 : nowMainPlayerPos.y;
    nowMainPlayerPos.x = nowMainPlayerPos.x > getMainGameBackGround().width - (int)getMainPlayerHitbox().width? getMainGameBackGround().width - (int)getMainPlayerHitbox().width : nowMainPlayerPos.x;
    nowMainPlayerPos.y = nowMainPlayerPos.y > getMainGameBackGround().height - (int)getMainPlayerHitbox().height ? getMainGameBackGround().height - (int)getMainPlayerHitbox().height : nowMainPlayerPos.y;


    // Set Player Pos
    setMainPlayerLoc(nowMainPlayerPos);
    updateMainPlayerHitbox2Loc();
    updateCenter();
    return;
}
#endif


void otherKeyDetection(){
    // In Game Menu
    if(IsKeyPressed(KEY_M)){
        if(shouldDrawInGameMenu())
            stopDrawingInGameMenu();
        else
            startDrawingInGameMenu();
    }

    // Noraml Attack 
    if(IsKeyDown(KEY_SPACE)){
        normalAttack();
    }
    if(IsKeyDown(KEY_LEFT_SHIFT)){
        specialAttack();
    }

    // DEBUG Spawn zombie
    #if DEBUG == 1
        if(IsKeyDown(KEY_S)){
            spawnZombie(LEVEL1V1, getMainPlayerLoc());
        }
    #endif
}