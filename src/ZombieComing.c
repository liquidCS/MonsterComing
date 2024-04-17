#include "raylib.h"
#include "menu.h"

int main(void)
{
    int screenWidth = 1920; 
    int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "ZombieComing");
    ToggleFullscreen();
    SetTargetFPS(60);

    // Menu Initialize
    initMenu();

    // quit detection
    bool shouldQuit = false;
    while (WindowShouldClose() == false && shouldQuit == false)
    {   
        BeginDrawing();

        ClearBackground(BLACK);
        
        if(shouldStartGame() == false){
            // Draw Menu
            drawMenu();
            shouldQuit = shouldExitGame() == true ? true : false;
        }
        if(shouldStartGame() == true){
            drawMainGame();
        }

        // Player
        // DrawTexturePro(scarfy, sourceRec, destRec, origin, (float)rotation, WHITE);
        
        EndDrawing();
    }
    CloseWindow();

    return 0;
}