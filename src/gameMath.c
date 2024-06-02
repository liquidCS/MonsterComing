#ifndef GAMEMATH_C
#define GAMEMATH_C

#include "raylib.h"
#include "gameMath.h"


int calUpgradeCost(int level){
    int cost = 2;
    cost = cost << level; // 2 ^ level + 1
    return cost;
}

float degree2radian(int degrees){
    float radians = degrees * PI / 180.0;
    return radians;
}

#endif