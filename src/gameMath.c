#ifndef GAMEMATH_C
#define GAMEMATH_C

#include "raylib.h"
#include "gameMath.h"


int calUpgradeCost(int level){
    int cost = 2;
    cost = cost << level; // 2 ^ level + 1
    return cost;
}

#endif