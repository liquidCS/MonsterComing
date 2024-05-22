#ifndef ZOMBIES_H
#define ZOMBIES_H

#include "raylib.h"

#define ZombieTypesCount 2
enum zombieTypes {ZTEMP1, ZTEMP2, FIRSTNODEZOMBIE}; // "FIRSTNODEZOMBIE" for identification for the first node of zombies

// For Zombie Health Bar
#define LEVEL1_HEALTHBAR_HEIGHT 5


typedef struct zombieNode{
    int zombieType; // enum zombieTypes
    int maxHealth;
    int health;
    float speed; // pixel per sec (PPS)
    // loot
    int dropXP;
    int dropCoin;
    // 
    Vector2 position;
    Vector2 center;
    Rectangle hitbox;
    // Link list of zombie
    struct zombieNode *nextZombie;
}zombie;


void initZombies(); 
void spawnZombie(int); // create new zombie with specified type
void killZombie(zombie *, zombie *);

void drawZombies(); // draw all zombies
void drawZombieDamageValue(zombie *, int);
void zombieMovement(); // move zombie towards the player

void zombieCheck();

// Clear All Zombies in Link list
void freeAllZombie();

zombie * getZombies();

#endif