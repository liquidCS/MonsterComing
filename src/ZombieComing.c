#include "raylib.h"
#include "menu.h"
#include "mainGame.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    InitWindow(screenWidth, screenHeight, "ZombieComing");
    // ToggleFullscreen();
    SetTargetFPS(60);

    // Menu Initialize
    initMenu();
    srand(time(NULL));

    // Quit Game Detection
    bool shouldQuit = false;
    // Game Loop
    while (WindowShouldClose() == false && shouldQuit == false)
    {
        // RayLib Start Drawing
        BeginDrawing();

        if(shouldStartGame() == false){
            // Draw Menu
            drawMenu();
            shouldQuit = shouldExitGame();
        }
        if(shouldStartGame() == true){
            // Run Main Game
            drawMainGame();
        }
        // RayLib End Drawing
        EndDrawing();
    }
    // Unload game
    endMainGame();
    // RauLib Close Window
    CloseWindow();

    return 0;
}
