#ifndef MAINPLAYER_H
#define MAINPLAYER_H

#include "raylib.h"

// Character Selection
enum characterSelections {WARRIOR, NINJA, WITCH};


struct player
{
    enum characterSelections character;
    Vector2 position;
    Vector2 center;
    Texture2D texture;
    Rectangle hitbox;
    float animationChangeRate; // ms per change
    float speed; // pixel per sec (PPS)
    int level;
    int xp;
    int coins;
    int currHealth;
    int maxHealth;
    // Attacks
    int normalAttackDamage;
    float normalAttackCool;
    float normalAttackTimer;
};

enum MAINPLAYERSTATES {STOP, WALKING};
enum MAINPLAYERFACING {SOUTH, EAST, WEST, NORTH};

void initMainPlayer();
void drawMainPlayer();

void timerUpdate();

void normalAttack();
void drawAttack(); 

// update Hitbox to current mainPlayer.location;
void updateMainPlayerHitbox2Loc();
void updateCenter();

// variables
Vector2 getMainPlayerLoc();
void setMainPlayerLoc(Vector2);
Vector2 getMainPlayerCenter();

Rectangle getMainPlayerHitbox();

Texture2D getMainPlayerTexture();

float getMainPlayerSpeed();
void setMainPlayerSpeed(float);

int getMainPlayerState();
void setMainPlayerState(int);

int getMainPlayerFacing();
void setMainPlayerFacing(int);

// Attacks
int getNormalAttackDamage();
float getNormalAttackCool();
float getNormalAttackTimer();

// Health
int getMainPlayerCurrHealth();
int getMainPlayerMaxHealth();
// Coins
int getMainPlayerCoins();
void addMainPlayerCoin(int);
void minusMainPlayerCoin(int);

#endif
