#pragma once

// Platform-dependent functions

#define COLOR_BLACK   0
#define COLOR_RED     1
#define COLOR_GREEN   2
#define COLOR_YELLOW  3
#define COLOR_BLUE    4
#define COLOR_MAGENTA 5
#define COLOR_CYAN    6
#define COLOR_WHITE   7

namespace io {

void sleepFor(int time_ms);
void initializeScreen();
void clearScreen();
void refreshScreen();
void releaseScreen();
void hideCursor();
void showCursor();
int getScreenSizeX();
int getScreenSizeY();
void moveCursorTo(int x, int y);
void writeString(const char* str);
int waitForKey();

}