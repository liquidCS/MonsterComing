#ifndef MENUPAGES_H
#define MENUPAGES_H

#define SETTINGSPAGE_WIDTH 500
#define SETTINGSPAGE_HEIGHT 500
void drawSettingsPage();

#define STATISTICPAGE_WIDTH 500
#define STATISTICPAGE_HEIGHT 500
#define STATISTICPAGE_ITEM_GAP 70
#define STATISTICPAGE_WALLGAP_TITLE 40
#define STATISTICPAGE_WALLGAP_DATA 300

#define STATISTICPAGE_TITLE_FONTSIZE 30
#define STATISTICPAGE_DATA_FONTSIZE 40
void drawStatisticPage();

// gets
bool shouldQuitSettingsPage();
bool shouldQuitStatisticPage();

#endif