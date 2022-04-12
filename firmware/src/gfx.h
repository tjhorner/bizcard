#include <Arduino.h>
#include <mcurses.h>
#include <stddef.h>
#include "io.h"

#define DEFAULT_INTER_DELAY 100

namespace gfx {

void writeLine(const char* text, size_t after_delay, size_t inter_delay = DEFAULT_INTER_DELAY);
void drawPicture(const char* image, int X = -1, int Y = -1);
void clearArea();
void main();

}