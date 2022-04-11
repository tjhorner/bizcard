# Default Firmware

The firmware that comes pre-installed on each of the cards does a couple of things:

- Plays "Still Alive" from Portal on the buzzer
- Sets each Neopixel to a random color every time a note from the song plays
- Simulates the terminal-esque end scene from Portal in sync with the song over USB serial

The source for this firmware can be found in the `firmware` directory of the repository.

It utilizes both of the RP2040's cores: core 0 handles the terminal animation and core 1 handles the music. The notes are split up into segments that roughly correspond with verses in the song, and the animation is split up into these same segments to match. At the end of each segment, both cores will wait for their counterpart to finish before continuing. This means that the song will wait for the animation to finish before playing the next segment, and vice versa.

If you want to see the terminal animation in action, the easiest way is to plug the device into your computer, then view the terminal output from [this website](https://googlechromelabs.github.io/serial-terminal/). It uses Web Serial to connect to the device, so there's no installation required. Follow these steps:

1. Go [here](https://googlechromelabs.github.io/serial-terminal/). (Make sure you are using a supported browser. Notably, Firefox does not support the Web Serial API)
2. Click the "Connect" button (make sure the baud rate is set to 115200)
3. Plug in the device
4. Within 5 seconds of plugging it in, select it from the dropdown. It should be named "PCBusinessCard"
5. Enjoy the show!

If you want to view it natively from an actual terminal emulator, you can do that as well, but it's not as simple:

- **macOS**: From a terminal, run the command `screen /dev/cu.usbmodem* 115200` while the device is plugged in
- **Windows**: You can use [PuTTY](https://www.putty.org/) to access the device from a COM port. The baud rate is 115200
- **Linux**: You probably know what you are doing, but you can use the command `screen /dev/ttyUSB* 115200` to get started

I recommend resetting the device then connecting immediately after, this way the terminal is correctly set up. Otherwise, you'll start in the middle of the animation and things will look strange.

Or you can just watch this video, but that's kinda lame (turn up your volume!):

https://user-images.githubusercontent.com/2646487/162366428-906fa74b-1275-4396-9afb-aaf11e48caa4.mp4

## Acknowledgements

Big thanks to these folks for open sourcing their work, which this firmware incorporates much of:

- "Still Alive" MIDI: https://www.vgmusic.com/file/bfae50e09af58a8f4415968b79464346.html
- "Still Alive" terminal version, which I ported to work with Arduino: https://github.com/ivanp7/still-alive
- mcurses, a very slim implementation of ncurses: https://github.com/ChrisMicro/mcurses