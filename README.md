# PCBusiness Card

![](https://user-images.githubusercontent.com/2646487/161359757-6e8b9c71-aec6-4de1-924a-eec69777996f.png)

> **Note:** I'm still finalizing the PCB design and default firmware, so this repo is a bit barren for now. If you're reading this, I haven't given the business card to anyone yet, which means you're either very curious or just went back in the commit history (which, I guess, also implies curiosity).

Hiya! Welcome to the documentation for my... business card? Yep, my business card. Which is also a PCB. Chances are you received one from me and are curious enough to scan the QR code on the back.

In these docs, you'll find information on the specs, how to flash it, which peripherals are onboard, how to do cool stuff with it, and (if you received a bare board) where to source the parts you'll need to assemble it. You'll also find the source KiCad project files for the schematic and board, as well as the source for the firmware that is installed by default. These are open source under BY-CC-SA 4.0 and MIT, so feel free to base your own designs on them.

## Documentation

- [Bill of Materials](docs/bom.md)
- [Flashing Instructions](docs/flashing.md)
- [FAQ](docs/faq.md)

## Bare Board Assembly

If you received a bare board, you can find the list of parts you will need (and links to where you can buy them) in the [bill of materials](docs/bom.md). At the moment, this assumes you know how to solder really small surface-mount parts (there are a couple of 0402 parts on there)! So this isn't really a beginner project, unfortunately. I might make a through-hole version in the future (or make the SMD pads bigger, I guess), so that it's easier for beginners, but right now you need to be really good at soldering very precisely.

If, for some reason, you really really want an assembled board, there are services out there that will do it for you. Just Google around for "SMT assembly service" and you'll find one. Or you could just ask me. Let me know what you plan to use it for, and if I have any assembled ones lying around I will gladly send one over for you to tinker with! You know how to reach me :)

## Specs

Here is a summary of the things on the board, but you can find more detailed info below:

- **Microcontroller**: [RP2040](https://www.raspberrypi.com/products/rp2040)
- **Flash**: 16MB [W25Q128JVS](http://www.winbond.com/resource-files/w25q128jv_dtr%20revc%2003272018%20plus.pdf)
- **Clock**: 12MHz [X322512MSB4SI](https://lcsc.com/product-detail/SMD-Crystal-Resonators_Yangxing-Tech-X322512MSB4SI_C9002.html) crystal
- **Connectivity**: USB-C 2.0
- **Peripherals**
  - Piezo Buzzer
  - WS2812B (x4)
  - Reset Button
  - USB Boot Button
  - GPIO Headers

### Microcontroller

At the core of the board is an [RP2040](https://www.raspberrypi.com/products/rp2040/), a microcontroller from the same people who make the Raspberry Pi. It was chosen mostly because I heard of it once and decided it would be cool to include in a project, so there it is! It's relatively cheap, but pretty powerful. It is also extremely well-documented and has lots of community support, making it great to write your own firmware for.

- [RP2040 Datasheet](https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf)
- [RP2040 Documentation](https://www.raspberrypi.com/documentation/microcontrollers/rp2040.html)
- [Official C/C++ SDK](https://www.raspberrypi.com/documentation/microcontrollers/c_sdk.html)
- [Official MicroPython SDK](https://www.raspberrypi.com/documentation/microcontrollers/micropython.html)

### Flash

The prepopulated boards come with a hefty 16MB of onboard QSPI flash provided by the W25Q128JVS chip, which is recommended by the Raspberry Pi Foundation in their hardware design documentation. This means you can include lots of libraries in your code and not have to worry about running out of space. Plus, this is actually the maximum amount of flash storage the RP2040 supports, so you can utilize it to its full potential.

If you have a bare board and don't want to go with the W25Q128JVS, you can use any QSPI flash you want. There are more details in the [RP2040 datasheet](https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf#section_ssi), under section 4.10.

- [W25Q128JVS Datasheet](http://www.winbond.com/resource-files/w25q128jv_dtr%20revc%2003272018%20plus.pdf)

### Clock

The clock on the prepopulated boards is a 12MHz crystal. There's not much else to say here!

- [X322512MSB4SI Datasheet](https://datasheet.lcsc.com/lcsc/2103291203_Yangxing-Tech-X322512MSB4SI_C9002.pdf)

### Connectivity

In the top-left corner of the board you will find a USB-C receptacle, chosen simply because I really like USB-C, and it's very commonly used in other devices these days, so I'm sure you will have a cable lying around. Conveniently, the RP2040 actually has USB support built-in, so no additional components were required to get it to work.

### Peripherals

I included some peripherals on board so that it's not entirely boring when you plug it in, and if you want to reflash it with your own firmware you already have some stuff to play with!

#### Piezo Buzzer

The buzzer is connected to GPIO3, and is compatible with the Arduino framework's [tone method](https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/), so it's very easy to write code for.

On the prepopulated boards I used [this buzzer](https://lcsc.com/product-detail/Buzzers_CY-Changzhou-Chaoyin-Elec-Cy-SMD-9019-3040_C968734.html) just because it was the first one from JLCPCB that matched the footprint I used. If you have a bare board, you can use any passive 3V 9x9mm SMD buzzer, like [this one](https://www.digikey.com/en/products/detail/cui-devices/CPT-9019S-SMT-TR/6012432) from Digi-Key.

- [Datasheet](https://datasheet.lcsc.com/lcsc/2012111405_CY-Changzhou-Chaoyin-Elec-Cy-SMD-9019-3040_C968734.pdf)

#### WS2812B (aka NeoPixel)

There are four WS2812B RGB LEDs on the top-right of the board connected to GPIO25 that you can do whatever you want with. The cool thing about these LEDs is that they have a built-in driver chip and you can link them together to control as many as you want from just a single data pin. There are a couple of libraries you can use to drive them, but I like Adafruit's [NeoPixel library](https://github.com/adafruit/Adafruit_NeoPixel).

- [WS2812B Datasheet](https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf)

#### Reset & USB Boot Buttons

These aren't peripherals, per se, but I thought I would include them here anyway.

The reset button can be used to restart the RP2040, and the USB boot button can be held during boot to instruct the RP2040 to mount itself as a mass storage device so you can reflash it.

#### GPIO Headers

Also not really a peripheral, but very useful for connecting your own stuff! These are unpopulated by default to keep the profile small, but if you want to turn the card into basically a fully-fledged RP2040 dev board, you can solder some 2.54mm-pitch headers to the unpopulated pads. [Here](https://www.digikey.com/en/products/detail/adam-tech/PH2-12-UA/9830397) is a 2x6 pin header from Digi-Key that should fit nicely. There's also a [socket version](https://www.digikey.com/en/products/detail/sullins-connector-solutions/PPPC062LFBN-RC/810246) similar to what you would find on an Arduino Uno, if you prefer that.

Once you have soldered the headers, you can go ahead and use the labeled GPIO pins to connect whatever other peripherals you want to the board and make it truly your own. Have fun!