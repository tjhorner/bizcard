# Flashing Instructions

If you want to write your own code to run on the board, you can totally do that! You can write software for the RP2040 in a couple different ways, like the official [C/C++ SDK](https://www.raspberrypi.com/documentation/microcontrollers/c_sdk.html) or [MicroPython](https://www.raspberrypi.com/documentation/microcontrollers/micropython.html). But I prefer to use PlatformIO with the Arduino framework. It's very easy to set up and integrates nicely with VS Code, which I use as my main editor. You can use whatever you like, but I will go over how to set it up with PlatformIO in this guide since that's what the default firmware is built with.

## Building the Default Firmware

A good place to start is with the firmware that comes pre-flashed on the board, since it was designed to be used as a template for custom firmware.

There are a few prequisites you need before we begin:

- [Visual Studio Code](https://code.visualstudio.com)
- [PlatformIO](https://platformio.org/platformio-ide)
- A USB-C cable

Once you've downloaded all of the above, you should be good to go!

First, let's clone the repo:

```shell
git clone https://github.com/tjhorner/bizcard.git
```

Open the `firmware` directory in VS Code. PlatformIO should recognize this is a PIO project and give you several options in the sidebar under the quick access menu (it's the PIO logo -- kinda looks like an ant or alien or something). If you see options like "Build, "Upload", etc. then you should be good to go.

Plug the board into your computer, then press "Upload" from VS Code. After a short while (it needs to download all the dependencies and compile the firmware), it should automatically detect the board and flash it. If not, you may need to press and hold the button labeled "USB", then press "RST" simultaneously. Release both buttons and it should now show up as a drive on your computer. Try uploading again.

Once flashed successfully, you should see `[SUCCESS]` near the end of the terminal output. Ta-da! You're now ready to customize the firmware to fit your needs.

## Customizing the Firmware

The default firmware is designed to be used as a jumping-off point for custom firmware; it already includes examples of how to use the onboard peripherals like the piezo buzzer and Neopixels. It also uses the Arduino framework, providing a familiar way to access the hardware and GPIO pins. Take a look at `main.cpp` -- that should be enough to get you started!

If you followed the section above, flashing is exactly the same. Just re-run the upload after you've made your modifications. If you need any help, well... you know how to reach me :)