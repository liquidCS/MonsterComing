#ifndef INGAMEMENU_H
#define INGAMEMENU_H

#define INGAMEMENU_WIDTH 300
#define INGAMEMENU_HIGHT 500


#define UPGRADE_GAP_Y 50
#define UPGRADE_GAP_X 10
#define UPGRADE_BUTTON_GAP_X 175
#define UPGRADE_BAR_MAX 10
#define UPGRADE_BAR_OFFSET_Y 30
#define UPGRADE_BAR_GAP_X 5
#define UPGRADE_BAR_GAP_Y 50
#define UPGRADE_BAR_HEIGHT 5
#define UPGRADE_FONTSIZE 20
#define UPGRADE_COLOR GREEN
#define UPGRADE_BUTTON_WIDTH 100
#define UPGRADE_BUTTON_HIGHT 20
#define UPGRADE_BUTTON_TEXT "UPGRADE"
#define UPGRADE_OPTIONS_COUNT 5

typedef enum {HEALTH = 1, DAMAGE, ATTACK_SPEED} upgradeOptions;

void initInGameMenu();
void drawInGameMenu();

void startDrawingInGameMenu();
void stopDrawingInGameMenu();

bool shouldDrawInGameMenu();

#endif