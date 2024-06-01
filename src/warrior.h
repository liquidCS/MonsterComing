#ifndef WARRIOR_H
#define WARRIOR_H

#include "raylib.h"
#include "zombies.h"


#define NORMAL_ATTACK_WIDTH 100
#define NORMAL_ATTACK_HEIGHT 100

#define SPECIAL_ATTACK_WIDTH 300
#define SPECIAL_ATTACK_HEIGHT 50

#define ANIMATION_TIME 2

void initWarriorAttack();

void warriorNormalAttack();
void drawWarriorNormalAnimation(bool);

void warriorSpecialAttack();
void drawWarriorSpecialAnimation(bool);

#endif
