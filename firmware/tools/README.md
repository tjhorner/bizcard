# Tools

## `segment.js`

This script takes a JSON'd MIDI file (using [this website](https://www.visipiano.com/midi-to-json-converter/)) and splits it into segments then generates code to be used in `notes.h`. I wrote and used this to split up the Still Alive MIDI roughly into verses that match up with the animation that plays over the serial port. This way, they could easily be synced together.

## `oem.sh`

This is the script I use when flashing a new batch of cards. It first uploads a test firmware that blinks the Neopixels and beeps the buzzer, then uploads the default firmware. It makes it easy to flash a bunch one after another.