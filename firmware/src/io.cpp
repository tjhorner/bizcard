// Platform-dependent functions

#include "io.h"
#include <Arduino.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <mcurses.h>

namespace io {

void sleepFor(int time_ms)
{
  delay(time_ms);
}

void initializeScreen()
{
  Serial.begin(115200);
  initscr();
}

void clearScreen()
{
  attrset(A_NORMAL | F_YELLOW);
  clear();
}

void refreshScreen()
{
  refresh();
}

void releaseScreen()
{
  endwin();
  Serial.end();
}

void hideCursor()
{
  curs_set(0);
}

void showCursor()
{
  curs_set(1);
}

int getScreenSizeX()
{
  return MCURSES_COLS;
}

int getScreenSizeY()
{
  return MCURSES_LINES;
}

void moveCursorTo(int x, int y)
{
  move(y, x);
}

void writeString(const char *str)
{
  Serial.print(str);
}

int waitForKey()
{
  return getch();
}

}