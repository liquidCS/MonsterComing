#include "raylib.h"
#include "menu.h"
#include "mainGame.h"

int main(void)
{
    int screenWidth = 1920; 
    int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "ZombieComing");
    ToggleFullscreen();
    SetTargetFPS(60);

    // Menu Initialize
    initMenu();

    // Quit Game Detection
    bool shouldQuit = false;
    // Game Loop
    while (WindowShouldClose() == false && shouldQuit == false)
    {   
        BeginDrawing();
        
        if(shouldStartGame() == false){
            // Draw Menu
            drawMenu();
            shouldQuit = shouldExitGame() == true ? true : false;
        }
        if(shouldStartGame() == true){
            // Run Main Game
            drawMainGame();
        }
        
        EndDrawing();
    }
    CloseWindow();

    return 0;
}