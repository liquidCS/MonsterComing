#ifndef MAINPLAYER_H
#define MAINPLAYER_H

#include "raylib.h"

// Character Selection
enum characterSelections {WARRIOR, NINJA, WITCH};


struct player
{
    enum characterSelections character;
    Vector2 position; // Player Current Position on Map
    Vector2 center; // Player Texture Center Position
    Texture2D texture; // Player Texture to Draw on Screen
    Rectangle hitbox; // Hitbox for collision check
    
    float animationChangeRate; // Time(ms) per change
    float speed; // pixel per sec (PPS)
    int level; // Current Level 
    int xp; // Current Experience Level
    int coins; // Current Posessed Coin
    // **Health**
    int currHealth; // Current Health
    int maxHealth; // Max Health 
    // **Attacks**
    int normalAttackDamage; // Damage for Normal Attack
    float normalAttackCool; // Time(s) for Normal Attack Cool Down
    float normalAttackTimer; // Time(s) Current Cool Down Time

    int specialAttackDamage; // Damage for Special Attack
    float specialAttackCool; //  Time(s) for Special Attack Cool Down
    float specialAttackTimer; // Time(s) for Current Cool Down time

    float criticalHitPercentage; // Critical Hit Chances in %
};

enum MAINPLAYERSTATES {STOP, WALKING};
enum MAINPLAYERFACING {SOUTH, EAST, WEST, NORTH};

void initMainPlayer();
void drawMainPlayer();

void timerUpdate();

void normalAttack();
void specialAttack();
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

int getSpecialAttackDamage();
float getSpecialAttackCool();
float getSpecialAttackTimer();

float getCriticalHitPercentage();


// Health
int getMainPlayerCurrHealth();
int getMainPlayerMaxHealth();
// Coins
int getMainPlayerCoins();
void addMainPlayerCoin(int);
void minusMainPlayerCoin(int);

#endif
