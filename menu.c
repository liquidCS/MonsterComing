#ifndef MENU_C
#define MENU_C

#include "raygui.h"
#include "mainGame.h"


// Layout Settings
int BUTTON_X;
int BUTTON_Y;
#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 50
#define BUTTON_GAP (20 + BUTTON_HEIGHT)

// Title Settings and Fonts
// By https://www.dafont.com/stranger-back-in-the-night.font personal use only
Font TITLEFONT;
#define TITLE_FONT_SIZE 50
#define TITLE_FONT_SPACING 5.0f
#define TITLE "Zombie Coming"
Vector2 titleDim;
Vector2 TITLE_POS;

bool gameStart;
bool gameExit;

// load style from file and initialize variables
void initMenu(){
    // Game Start Detection
    gameStart = false;
    gameExit = false;

    // Load Style For UI
    GuiLoadStyle("resources/jungle.rgs");

    // Load Title Font
    TITLEFONT = LoadFont("resources/titleFont.ttf");

    // Initialize Title Location
    titleDim = MeasureTextEx(GetFontDefault(), TITLE, TITLE_FONT_SIZE, TITLE_FONT_SPACING);
    TITLE_POS.x = GetScreenWidth()/2 - titleDim.x;
    TITLE_POS.y = GetScreenHeight()/4;

    // Initialize Button Location
    BUTTON_X = GetScreenWidth()/2 - BUTTON_WIDTH/2;
    BUTTON_Y = GetScreenHeight()/2 - BUTTON_HEIGHT/2;
    return;
}

// Draw Menu and User Input Detections
void drawMenu(){
    // Draw Background
    ClearBackground(BLACK);

    // Draw Title
    DrawTextEx(GetFontDefault(), "Zombie Coming", TITLE_POS, TITLE_FONT_SIZE, TITLE_FONT_SIZE, RED);
    
    // Draw Buttons and Detections Player Input
    bool startButtonPress = false;
    startButtonPress = GuiButton((Rectangle){BUTTON_X, BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT}, "Start Game"); 
    bool settingButtonPress = false;
    settingButtonPress = GuiButton((Rectangle){BUTTON_X, BUTTON_Y+BUTTON_GAP, BUTTON_WIDTH, BUTTON_HEIGHT}, "Settings");
    bool creditButtonPress = false;
    creditButtonPress = GuiButton((Rectangle){BUTTON_X, BUTTON_Y+2*BUTTON_GAP, BUTTON_WIDTH, BUTTON_HEIGHT}, "Credit");
    bool quitButtonPress = false;
    quitButtonPress = GuiButton((Rectangle){BUTTON_X, BUTTON_Y+3*BUTTON_GAP, BUTTON_WIDTH, BUTTON_HEIGHT}, "Quit");

    // Button Press Function Call
    if(startButtonPress == true){
        // Load Main Game
        initMainGame();
        gameStart = true;
    }
    if(settingButtonPress == true){
        // Load Settings Menu
    }
    if(creditButtonPress == true){
        // Load Credit Page

    }
    if(quitButtonPress == true){
        // Exit
        gameExit = true;
    }

    return;
}

bool shouldStartGame(){
    return gameStart;
}

bool shouldExitGame(){
    return gameExit;
}

#endif