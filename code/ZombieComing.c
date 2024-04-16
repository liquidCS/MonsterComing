#include "raylib.h"
#include "menu.h"

int main(void)
{
    int screenWidth = 1920; 
    int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "ZombieComing");
    ToggleFullscreen();
    SetTargetFPS(60);

    Texture2D scarfy = LoadTexture("resources/dinosaur.png");\
    int frameWidth = scarfy.width/6;
    int frameHeight = scarfy.height;        
    Rectangle sourceRec = { 0.0f, 0.0f, (float)frameWidth, (float)frameHeight };
    Rectangle destRec = { screenWidth/2.0f, screenHeight/2.0f, frameWidth*2.0f, frameHeight*2.0f };
    Vector2 origin = { (float)frameWidth, (float)frameHeight };
    int rotation = 0;

    //load UI style
    loadMenuStyle();

    while (WindowShouldClose() == false)
    {   
        rotation++;
        BeginDrawing();
        // Draw Word
        ClearBackground(RAYWHITE);
        DrawText("Player 1", 20, 20, 30, BLACK);
        
        // Draw Menu
        drawMenu();

        // Player
        // DrawTexturePro(scarfy, sourceRec, destRec, origin, (float)rotation, WHITE);
        
        EndDrawing();
    }
    CloseWindow();

    return 0;
}