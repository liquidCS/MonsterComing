#ifndef ZOMBIEWAVES_H
#define ZOMBIEWAVES_H

/*
wave includes generate zombies (different levels of zombies), loot boxs
calculate when the wave arrived by time and zombie count.

Zombie spawning:
1. every wave n will spawn n*5 zombies
2. after every 5 wave will unlock new level zombie
3. every zombie unloclk will have the same chance of spawning

*/

#define WAVETIME 1.0f
#define SPAWN_RADIUS 500

void initWaves(); // init Waves, Load settings

void waveLoop(); // check wave status, calculate time, create new wavs...;

int getCurrWave(); // get curr wave nubmer 

float getNextWaveTime(); // get time till next wave
#endif