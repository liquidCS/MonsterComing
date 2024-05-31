#ifndef SAVEHANDLER_H
#define SAVEHANDLER_H

#include "raylib.h"
#include "basic.h"

#define STATISTICDATADIR "saves/statistic"

typedef struct statisticData{
    ll gamesPlayed;
    ll zombiesKilled;
    ll coinsEarned;
    ll damagedMade;
    ll lostedHealth;
} statisticData;

statisticData * initData();
void initSaves();
void closeSaves();

typedef enum{GAMESPLAYED, ZOMBIESKILLED, COINSEARNED, DAMAGEDMADE, LOSTEDHEALTH} statisticTypes;
void writeCurrStatistic(statisticTypes, ll);
ll getCurrStatistic(statisticTypes);
void saveCurrStatistic();

#endif