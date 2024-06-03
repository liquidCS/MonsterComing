#ifndef SAVEHANDLER_C
#define SAVEHANDLER_C

#include "raylib.h"
#include "saveHandler.h"
#include <stdio.h>
#include <stdlib.h>

statisticData *currStatisticData;

statisticData * initData();

void initSaves(){
    // clear previous data
    free(currStatisticData);
    // Save blank data if save file does not exist
    if(!FileExists(STATISTICDATADIR)){
        printf("Creating file\n");
        FILE *file = fopen(STATISTICDATADIR, "wb");

        statisticData *temp = initData();
        fwrite(temp, sizeof(statisticData), 1, file); // Write default data into file
        
        free(temp); // free temp statisticData
        fclose(file); // close file atfter creating file
    }
    FILE *file = fopen(STATISTICDATADIR, "rb");
    
    // Load Statistic Data
    currStatisticData = (statisticData *)malloc(sizeof(statisticData));
    fread(currStatisticData, sizeof(statisticData), 1, file);
    printf("LOAD: %lld %lld %lld %lld %lld %lld\n", currStatisticData->gamesPlayed, currStatisticData->zombiesKilled, currStatisticData->coinsEarned, currStatisticData->damagedMade, currStatisticData->lostedHealth, currStatisticData->maxWave);
    fclose(file);
   return;
}

void saveCurrStatistic(){
    FILE *file = fopen(STATISTICDATADIR, "wb");
    fwrite(currStatisticData, sizeof(statisticData), 1, file);
    printf("Write: %lld %lld %lld %lld %lld %lld\n", currStatisticData->gamesPlayed, currStatisticData->zombiesKilled, currStatisticData->coinsEarned, currStatisticData->damagedMade, currStatisticData->lostedHealth, currStatisticData->maxWave);
    fclose(file);
    free(currStatisticData);
    return;
}

void writeCurrStatistic(statisticTypes statisticType, ll value){
    if(statisticType == GAMESPLAYED){
        currStatisticData->gamesPlayed += value;
    }
    else if(statisticType == ZOMBIESKILLED){
        currStatisticData->zombiesKilled += value;
    }
    else if(statisticType == COINSEARNED){
        currStatisticData->coinsEarned += value;
    }
    else if(statisticType == DAMAGEDMADE){
        currStatisticData->damagedMade += value;
    }
    else if(statisticType == LOSTEDHEALTH){
        currStatisticData->lostedHealth += value;
    }
    else if(statisticType == MAXWAVE){
        currStatisticData->maxWave += value;
    }
    return;
}

ll getCurrStatistic(statisticTypes statisticType){
    if(statisticType == GAMESPLAYED){
        return currStatisticData->gamesPlayed;
    }
    else if(statisticType == ZOMBIESKILLED){
        return currStatisticData->zombiesKilled;
    }
    else if(statisticType == COINSEARNED){
        return currStatisticData->coinsEarned;
    }
    else if(statisticType == DAMAGEDMADE){
        return currStatisticData->damagedMade;
    }
    else if(statisticType == LOSTEDHEALTH){
        return currStatisticData->lostedHealth;
    } 
    else if(statisticType == MAXWAVE){
        return currStatisticData->maxWave;
    }
}

// Create File - Used When save file does not exist
statisticData * initData(){
    statisticData *temp = malloc(sizeof(statisticData));
    *temp = (statisticData){0, 0, 0, 0, 0, 0};
    return temp;
}


#endif
