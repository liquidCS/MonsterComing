#ifndef WARRIOR_H
#define WARRIOR_H

#include "raylib.h"
#include "zombies.h"


#define NORMAL_ATTACK_WIDTH 100
#define NORMAL_ATTACK_HEIGHT 100

#define ANIMATION_TIME 2

void initWarriorAttack();

void warriorNormalAttack();
void drawWarriorNormalAnimation(bool);

#endif
