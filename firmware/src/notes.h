#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "pins.h"

namespace notes {

struct NoteDefinition
{
  unsigned int frequency;
  double duration;
  double delayAfter;
  bool pause; // should pause at this note
};

const NoteDefinition notes[] = {
    {784, 250, 250, false},
    {740, 250, 250, false},
    {659, 250, 250, false},
    {659, 250, 250, false},
    {740, 250, 0, true},
    {440, 250, 250, false},
    {784, 250, 250, false},
    {740, 250, 250, false},
    {659, 250, 250, false},
    {659, 500, 500, false},
    {740, 250, 750, false},
    {587, 500, 500, false},
    {659, 250, 250, false},
    {440, 500, 0, true},
    {440, 250, 250, false},
    {659, 500, 500, false},
    {740, 250, 250, false},
    {784, 750, 750, false},
    {659, 250, 250, false},
    {554, 500, 500, false},
    {587, 750, 750, false},
    {659, 500, 500, false},
    {440, 250, 250, false},
    {440, 500, 500, false},
    {740, 500, 0, true},
    {784, 250, 250, false},
    {740, 250, 250, false},
    {659, 250, 250, false},
    {659, 250, 250, false},
    {740, 250, 0, true},
    {440, 250, 250, false},
    {784, 250, 250, false},
    {740, 250, 250, false},
    {659, 250, 250, false},
    {659, 500, 750, false},
    {740, 250, 250, false},
    {587, 500, 750, false},
    {659, 250, 250, false},
    {440, 500, 0, true},
    {659, 500, 500, false},
    {740, 250, 250, false},
    {784, 750, 750, false},
    {659, 250, 250, false},
    {554, 750, 750, false},
    {587, 250, 250, false},
    {659, 250, 0, true},
    {440, 250, 250, false},
    {587, 250, 250, false},
    {659, 250, 250, false},
    {698, 250, 250, false},
    {659, 250, 250, false},
    {587, 250, 250, false},
    {523, 250, 0, true},
    {440, 250, 250, false},
    {466, 250, 250, false},
    {523, 500, 500, false},
    {698, 500, 500, false},
    {659, 250, 250, false},
    {587, 250, 250, false},
    {587, 250, 250, false},
    {523, 250, 250, false},
    {587, 250, 250, false},
    {523, 250, 250, false},
    {523, 500, 500, false},
    {523, 250, 0, true},
    {440, 250, 250, false},
    {466, 250, 250, false},
    {523, 500, 500, false},
    {698, 500, 500, false},
    {784, 250, 250, false},
    {698, 250, 250, false},
    {659, 250, 250, false},
    {587, 250, 250, false},
    {587, 250, 250, false},
    {659, 250, 250, false},
    {698, 500, 500, false},
    {698, 250, 0, true},
    {784, 250, 250, false},
    {880, 250, 250, false},
    {932, 250, 250, false},
    {932, 250, 250, false},
    {880, 500, 500, false},
    {784, 500, 500, false},
    {698, 250, 250, false},
    {784, 250, 250, false},
    {880, 250, 250, false},
    {880, 250, 250, false},
    {784, 500, 500, false},
    {698, 500, 0, true},
    {587, 250, 250, false},
    {523, 250, 250, false},
    {587, 250, 250, false},
    {698, 250, 250, false},
    {698, 250, 250, false},
    {659, 500, 500, false},
    {659, 250, 250, false},
    {740, 250, 250, false},
    {740, 1000, 0, true},
    {440, 250, 250, false},
    {784, 250, 250, false},
    {740, 250, 250, false},
    {659, 250, 250, false},
    {659, 250, 250, false},
    {740, 250, 0, true},
    {784, 250, 250, false},
    {740, 250, 250, false},
    {659, 250, 250, false},
    {659, 750, 750, false},
    {740, 250, 250, false},
    {587, 500, 500, false},
    {659, 500, 500, false},
    {440, 500, 0, true},
    {659, 500, 500, false},
    {740, 250, 250, false},
    {784, 750, 750, false},
    {659, 500, 500, false},
    {554, 500, 500, false},
    {587, 250, 250, false},
    {659, 750, 750, false},
    {440, 250, 250, false},
    {440, 500, 500, false},
    {740, 500, 0, true},
    {440, 250, 250, false},
    {784, 250, 250, false},
    {740, 250, 250, false},
    {659, 250, 250, false},
    {659, 250, 250, false},
    {740, 250, 0, true},
    {440, 250, 250, false},
    {784, 250, 250, false},
    {740, 250, 250, false},
    {659, 250, 250, false},
    {659, 500, 750, false},
    {740, 250, 250, false},
    {587, 500, 750, false},
    {659, 250, 250, false},
    {440, 500, 0, true},
    {659, 500, 500, false},
    {740, 250, 250, false},
    {784, 750, 750, false},
    {659, 500, 500, false},
    {554, 500, 500, false},
    {587, 250, 250, false},
    {659, 250, 500, false},
    {440, 250, 250, false},
    {587, 250, 250, false},
    {659, 250, 250, false},
    {698, 250, 250, false},
    {659, 250, 250, false},
    {587, 250, 250, false},
    {523, 250, 0, true},
    {440, 250, 250, false},
    {466, 250, 250, false},
    {523, 500, 500, false},
    {698, 500, 500, false},
    {659, 250, 250, false},
    {587, 250, 250, false},
    {587, 250, 250, false},
    {523, 250, 250, false},
    {587, 250, 250, false},
    {523, 250, 250, false},
    {523, 500, 500, false},
    {523, 500, 500, false},
    {440, 250, 250, false},
    {466, 250, 250, false},
    {523, 500, 500, false},
    {698, 500, 500, false},
    {784, 250, 250, false},
    {698, 250, 250, false},
    {659, 250, 250, false},
    {587, 250, 250, false},
    {587, 250, 250, false},
    {659, 250, 250, false},
    {698, 500, 500, false},
    {698, 500, 0, true},
    {784, 250, 250, false},
    {880, 250, 250, false},
    {932, 250, 250, false},
    {932, 250, 250, false},
    {880, 500, 500, false},
    {784, 500, 0, true},
    {698, 250, 250, false},
    {784, 250, 250, false},
    {880, 250, 250, false},
    {880, 250, 250, false},
    {784, 250, 250, false},
    {698, 250, 250, false},
    {698, 500, 0, true},
    {587, 250, 250, false},
    {523, 250, 250, false},
    {587, 250, 250, false},
    {698, 250, 250, false},
    {698, 250, 250, false},
    {659, 500, 500, false},
    {659, 250, 250, false},
    {740, 250, 250, false},
    {740, 1000, 0, true},
    {784, 125, 125, false},
    {784, 125, 125, false},
    {740, 250, 250, false},
    {659, 250, 250, false},
    {659, 375, 375, false},
    {740, 375, 0, true},
    {440, 250, 250, false},
    {784, 250, 250, false},
    {740, 250, 250, false},
    {659, 250, 250, false},
    {659, 500, 750, false},
    {740, 250, 250, false},
    {587, 500, 750, false},
    {659, 250, 250, false},
    {440, 500, 0, true},
    {659, 500, 500, false},
    {740, 250, 250, false},
    {784, 750, 750, false},
    {659, 500, 500, false},
    {554, 500, 500, false},
    {587, 250, 250, false},
    {659, 750, 750, false},
    {440, 250, 250, false},
    {440, 500, 500, false},
    {740, 500, 0, true},
    {784, 250, 250, false},
    {740, 250, 250, false},
    {659, 250, 250, false},
    {659, 312.5, 312.5, false},
    {740, 250, 2937.5, false},
    {784, 250, 250, false},
    {740, 250, 250, false},
    {659, 250, 250, false},
    {659, 500, 750, false},
    {740, 250, 250, false},
    {587, 500, 750, false},
    {659, 250, 250, false},
    {440, 500, 0, true},
    {659, 500, 500, false},
    {740, 250, 250, false},
    {784, 750, 750, false},
    {659, 500, 500, false},
    {554, 500, 500, false},
    {587, 250, 250, false},
    {659, 250, 500, false},
    {440, 250, 250, false},
    {587, 250, 250, false},
    {659, 250, 250, false},
    {698, 250, 250, false},
    {659, 250, 250, false},
    {587, 250, 250, false},
    {523, 250, 0, true},
    {440, 250, 250, false},
    {466, 250, 250, false},
    {523, 500, 500, false},
    {698, 500, 500, false},
    {659, 250, 250, false},
    {587, 250, 0, true},
    {587, 250, 250, false},
    {523, 250, 250, false},
    {587, 250, 250, false},
    {523, 250, 250, false},
    {523, 500, 500, false},
    {523, 500, 0, true},
    {440, 250, 250, false},
    {466, 250, 250, false},
    {523, 500, 500, false},
    {698, 500, 500, false},
    {784, 250, 250, false},
    {698, 250, 250, false},
    {659, 250, 250, false},
    {587, 250, 250, false},
    {587, 250, 250, false},
    {659, 250, 250, false},
    {698, 500, 500, false},
    {698, 500, 0, true},
    {784, 250, 250, false},
    {880, 250, 250, false},
    {932, 250, 250, false},
    {932, 250, 250, false},
    {880, 250, 250, false},
    {784, 250, 250, false},
    {784, 500, 0, true},
    {698, 250, 250, false},
    {784, 250, 250, false},
    {880, 250, 250, false},
    {880, 250, 250, false},
    {784, 250, 250, false},
    {698, 250, 250, false},
    {698, 500, 0, true},
    {587, 250, 250, false},
    {523, 250, 250, false},
    {587, 250, 250, false},
    {698, 250, 250, false},
    {698, 250, 250, false},
    {659, 500, 500, false},
    {659, 250, 250, false},
    {740, 250, 250, false},
    {740, 1000, 0, true},
    {880, 250, 250, false},
    {880, 250, 250, false},
    {988, 250, 250, false},
    {880, 250, 250, false},
    {740, 250, 250, false},
    {587, 500, 500, false},
    {659, 250, 250, false},
    {880, 250, 250, false},
    {880, 500, 0, true},
    {880, 250, 250, false},
    {880, 250, 250, false},
    {880, 250, 250, false},
    {988, 250, 250, false},
    {880, 250, 250, false},
    {740, 250, 250, false},
    {587, 500, 500, false},
    {659, 250, 250, false},
    {740, 250, 250, false},
    {740, 500, 0, true},
    {880, 250, 250, false},
    {880, 250, 250, false},
    {880, 250, 250, false},
    {988, 250, 250, false},
    {880, 250, 250, false},
    {740, 250, 250, false},
    {587, 500, 500, false},
    {659, 250, 250, false},
    {740, 250, 250, false},
    {740, 500, 0, true},
    {880, 250, 250, false},
    {880, 250, 250, false},
    {988, 250, 250, false},
    {880, 250, 250, false},
    {740, 250, 250, false},
    {587, 500, 500, false},
    {659, 250, 250, false},
    {740, 250, 250, false},
    {740, 500, 0, true},
    {880, 250, 250, false},
    {880, 250, 250, false},
    {880, 250, 250, false},
    {988, 250, 250, false},
    {880, 250, 250, false},
    {740, 250, 250, false},
    {587, 500, 500, false},
    {659, 250, 250, false},
    {740, 250, 250, false},
    {740, 500, 1500, false},
    {784, 250, 250, false},
    {880, 250, 250, false},
    {880, 500, 1500, false},
    {784, 250, 250, false},
    {740, 250, 250, false},
    {740, 500, 0, true}};

void setup();
void playNextSegment();

}