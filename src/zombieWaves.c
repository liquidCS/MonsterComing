#ifndef ZOMBIEWAVES_C
#define ZOMBIEWAVES_C

#include "raylib.h"
#include "mainPlayer.h"
#include "zombieWaves.h"
#include "zombies.h"
#include "gameMath.h"
#include "basic.h"
#include "saveHandler.h"
#include <math.h>
#include <stdlib.h>

int currWave;
float waveTimer;

void initWaves(){
    currWave = 0;
    waveTimer = 0.0;

    return;
}

void waveLoop(){
    waveTimer += GetFrameTime();
    if(waveTimer >= WAVETIME){
        waveTimer = 0; // rest wave timer
        currWave++;  // next wave

        // saves
        if(currWave > getCurrStatistic(MAXWAVE))
            writeCurrStatistic(MAXWAVE, currWave-getCurrStatistic(MAXWAVE));
    
        // Calculate the Type of Zombie that is allowed to spawn
        int zombieTypeCount = (currWave/5) + 1;
        if(zombieTypeCount > ZombieTypesCount) zombieTypeCount = zombieTypeCount;

        int zombieSpawnCount = currWave*3; // calculate the amount of zombies to spawn
        for(int i=0; i<zombieSpawnCount; i++){
            int degree = rand()%360;
            Vector2 spawnLoc = {getMainPlayerCenter().x + SPAWN_RADIUS*cos(degree2radian(degree)), getMainPlayerCenter().y + SPAWN_RADIUS*sin(degree2radian(degree))}; // generate spawn loacation
            int spawnType = rand()%zombieTypeCount; // random spawn type

            spawnZombie(spawnType, spawnLoc); // spawn zombie
        }
        #if DEBUG == 1
            DrawCircleLines(getMainPlayerCenter().x, getMainPlayerCenter().y, SPAWN_RADIUS, PURPLE);
        #endif
    }
    
    return;
}

int getCurrWave(){
    return currWave;
}

float getNextWaveTime(){
    return WAVETIME - waveTimer;
}


#endif