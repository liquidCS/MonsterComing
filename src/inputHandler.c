#ifndef INPUTHANDLER_C
#define INPUTHANDLER_C
#define FOURTYFIVE_DEGREE 0.785398163397448309

#include <math.h>
#include "raylib.h"
#include "mainPlayer.h"
#include "mainGame.h"

void inputHandle(){
    Vector2 nowMainPlayerPos = getMainPlayerLoc();
    float dt = GetFrameTime();
    double degree;
    // Check if Player is Going For Two Direction at the Same Time
    if((IsKeyDown(KEY_UP) || IsKeyDown(KEY_DOWN) && (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_RIGHT))))
        degree = FOURTYFIVE_DEGREE;
    else
        degree = 0;
        
    if(IsKeyDown(KEY_LEFT)){
        nowMainPlayerPos.x -= getMainPlayerSpeed()*dt*cos(degree);
    }
    if(IsKeyDown(KEY_RIGHT)){
        nowMainPlayerPos.x += getMainPlayerSpeed()*dt*cos(degree);
    }
    if(IsKeyDown(KEY_UP)){
        nowMainPlayerPos.y -= getMainPlayerSpeed()*dt*cos(degree);
    }
    if(IsKeyDown(KEY_DOWN)){
        nowMainPlayerPos.y += getMainPlayerSpeed()*dt*cos(degree);
    }
    // Postion Check
    // The Player's Cordinate is On the Top Right Corner of Player Texture so When Checking for Right and Left Bound
    // BackGround.Width/Height - Player.Width/Height is necessary
    nowMainPlayerPos.x = nowMainPlayerPos.x < 0 ? 0 : nowMainPlayerPos.x;
    nowMainPlayerPos.y = nowMainPlayerPos.y < 0 ? 0 : nowMainPlayerPos.y;
    nowMainPlayerPos.x = nowMainPlayerPos.x > getMainGameBackGround().width - getMainPlayerTexture().width? getMainGameBackGround().width - getMainPlayerTexture().width : nowMainPlayerPos.x;
    nowMainPlayerPos.y = nowMainPlayerPos.y > getMainGameBackGround().height - getMainPlayerTexture().height ? getMainGameBackGround().height - getMainPlayerTexture().height : nowMainPlayerPos.y;
    // Set Player Pos
    setMainPlayerLoc(nowMainPlayerPos);
    return;
}
#endif