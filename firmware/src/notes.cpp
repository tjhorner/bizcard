#include "notes.h"

namespace notes {

unsigned int currentNoteIndex = 0;

Adafruit_NeoPixel neopixels(NEOPIXEL_COUNT, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);

  neopixels.begin();
  neopixels.clear();
  neopixels.show();
}

void playNextSegment()
{
  if (currentNoteIndex >= sizeof(notes) / sizeof(NoteDefinition))
  {
    currentNoteIndex = 0;
  }

  while (currentNoteIndex < sizeof(notes) / sizeof(NoteDefinition))
  {
    NoteDefinition note = notes[currentNoteIndex];

    tone(BUZZER_PIN, note.frequency, note.duration);
    
    for (int i = 0; i < NEOPIXEL_COUNT; i++)
    {
      neopixels.setPixelColor(i, neopixels.Color(random(0, 100), random(0, 100), random(0, 100)));
    }

    neopixels.show();
    delay(note.delayAfter);

    currentNoteIndex++;
    if (note.pause)
      break;
  }
}

}