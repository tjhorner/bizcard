#ifndef OEMTEST

#include "gfx.h"
#include "notes.h"
#include "main.h"

// mcurses helpers
void Arduino_putchar(uint8_t c)
{
  Serial.write(c);
}

char Arduino_getchar()
{
  while (!Serial.available());
  return Serial.read();
}

// Core 0 entrypoint (handles graphics)
void setup()
{
  setFunction_putchar(Arduino_putchar);
  setFunction_getchar(Arduino_getchar);
}

void loop()
{
  // Give user some time to open serial connection
  delay(5000);
  gfx::main();
}

// Core 1 entrypoint (handles sound)
void setup1()
{
  notes::setup();
}

void loop1()
{
  // Indicate to core 0 that we're ready to continue animation
  rp2040.fifo.push(1);

  // Wait for core 0 to indicate that it's time to play the next segment
  rp2040.fifo.pop();

  notes::playNextSegment();
}

#endif