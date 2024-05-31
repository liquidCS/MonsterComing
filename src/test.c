#include "saveHandler.h"
#include <stdio.h>
// gcc -o test test.c saveHandler.c -lraylib -lgdi32 -lwinmm

int main(){
    initSaves();
    writeCurrStatistic(GAMESPLAYED, 100);
    saveCurrStatistic();
    initSaves();
    // saveCurrStatistic();
    return 0;
}