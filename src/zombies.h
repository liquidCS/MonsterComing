#ifndef ZOMBIES_H
#define ZOMBIES_H

#include "raylib.h"
#include "mainPlayer.h"

#define ZombieTypesCount 2
enum zombieTypes {LEVEL1V1, LEVEL1V2, FIRSTNODEZOMBIE}; // "FIRSTNODEZOMBIE" for identification for the first node of zombies

// For Zombie Health Bar
#define LEVEL1_HEALTHBAR_HEIGHT 5
typedef enum {RIGHT, LEFT} ZOMBIE_FACING;

typedef struct zombieNode{
    int zombieType; // enum zombieTypes
    int maxHealth; // Maxium Zombie Health
    int health; // Current Zombie Health
    float speed; // pixel per sec (PPS)
    // loot
    int dropXP; // Amount of XP Drop When Killed
    int dropCoin; // Amount of coins Drop When Killed

    Vector2 position;
    Vector2 center;
    Rectangle hitbox;

    // Draw and Animation
    ZOMBIE_FACING facing;

    // Link list of zombie
    struct zombieNode *nextZombie;
}zombie;

// Zombie
#define ZOMBIE_SIZE 64
#define ZOMBIE_FRAMES 4
#define ZOMBIE_ANIMATION_TIME 0.2f // for one cycle

// Animation Time
#define NORMAL_DAMAGE_TIME 0.2f
#define CRITICAL_DAMAGE_TIME 1.0f
#define NORMAL_DAMAGE_FONTSIZE 15
#define CRITICAL_DAMAGE_FONTSIZE 20
#define NORMAL_DAMAGE_COLOR BLUE
#define CRITICAL_DAMAGE_COLOR GOLD

typedef enum {NORMAL, CRITICAL} damageTypes;
typedef struct zombieDamageNode{
    int damage;
    Vector2 position;
    damageTypes damageType;
    float currTime;
    float existTime;
    struct zombieDamageNode *nextDamage;
} zombieDamage;


void initZombies(); // init texture, sound...
void spawnZombie(int, Vector2); // create new zombie with specified type
void killZombie(zombie *, zombie *);

void drawZombies(); // draw all zombies
void zombieMovement(); // move zombie towards the player

void zombieCheck(); // check if zombie died

// Draw Zombie Damage
void addZombieDamageAnimation(zombie *, int, damageTypes); // add new zombie Damage Value
void drawZombieDamageValue(); // draw existed zombie damage value



// Clear All Zombies in Link list
void freeAllZombie();

zombie * getZombies(); // get Zombie Link list

int getZombieCount(); // get Alive Zombie Number



#endif