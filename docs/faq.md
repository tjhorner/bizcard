# FAQ

## Why?

I've always been fascinated by unique business cards, and I've seen a couple of PCB business cards in the past ([here](https://www.youtube.com/watch?v=zHVrY_xLM3c) is a really cool one). So I thought it would be cool to make one of my own, and hopefully make a great first impression to whoever I give them to. It was also an excellent learning experience in electronics design, giving me knowledge that I can use in future projects.

## There's a "v2" or "v3" in the top-left of the board, what does it mean?

This is, as you probably guessed, how I version the different revisions of the board.

### v1

While there was technically a v1 board, it wasn't labelled as such and was never distributed to anyone. I made a silly mistake in the design which rendered it totally inoperable. So all it does is sit there and look cool.

### v2

If you find yourself in possession of a v2 board, congratulations! There were only ever 5 of these made, and only 2 of them were preassembled. This version has a defect where the decoupling capacitor for the Neopixels were connected inline with the circuit instead of to ground. You may notice a solder bridge where the capacitor is supposed to be.

### v3

- The decoupling capacitor for the Neopixels is now connected to ground
- There is now one decoupling capacitor for each Neopixel
- CC1 and CC2 on the USB connector are now connected to ground with a 5.1k resistor in between
- There's a 5V voltage regulator for the Neopixels, because VBUS can actually be higher than 5V
- The silkscreen for the info on the back was resized to not overlap with the pads
- Added test pads for QSPI_SS, VBUS, and USB+/-
- Changed the buttons to both save on cost and make the profile smaller

### v4

- Removed 5V regulator, because I am dumb
- Added optional SWD headers for debugging (this will work well: https://www.adafruit.com/product/752)
- Neopixel GPIO pin changed to 24 (from 25)
- Added built-in LED on GPIO 25
  - This change was made because most other RP2040 boards have an LED on this pin, and it's where the Arduino framework expects it to be
- Removed reference designators from silkscreen to make it look cleaner
- Swapped GND and 3V3 on the headers, because it makes more sense that GND is pin 1
- KiCad DRC rules modified to use JLCPCB design capabilities
- Other minor design changes