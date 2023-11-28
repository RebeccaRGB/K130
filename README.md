# K130
Battlestation keyboard with 130 keys!

I have successfully built and used two of these keyboards, so the design and software is pretty much done, but the documentation is still a work in progress.

## Stuff to Get
* 130x Cherry MX compatible keyswitches
* 130x through-hole 1N4148 diodes
* 1x through-hole 1-pin male header
* 3x through-hole 4-pin 2.54mm-spacing male header
* 3x through-hole 5-pin 2.54mm-spacing male header
* 1x through-hole 11-pin 2.54mm-spacing male header
* 1x through-hole 12-pin 2.54mm-spacing male header
* 2x through-hole 14-pin 2.54mm-spacing male header
* 10x Mill-Max Manufacturing Corp 0906-8-15-20-76-14-11-0 POGO pins (FANCY!)
* 1x Teensy 4.0 microcontroller
* 1x through-hole 6-switch DIP switches
* 3x through-hole 150 ohm resistors
* 3x through-hole LEDs *or* 3x through-hole NeoPixel LEDs *or* 1x NeoPixel strip
* 1x USB-B connector *or* 1x microUSB-B connector
* 2x 2u stabilizers
* a standard set of keycaps
* a case specifically from a Sun Microsystems Type 5c keyboard (these are plentiful on eBay and you don't have to feel bad about gutting one since the membrane on these things is pure crap)

## Stuff to Make
* 1x keyboard matrix PCB, made from the Gerber files in the `K130-matrix-gerber` directory
* 1x keyboard encoder PCB, made from the Gerber files in the `K130-encoder-gerber` directory
* 1x aluminum mounting plate, made from the `K130-plate.svg` file
* a bunch of additional keycaps for the 30 or so other keys, made from the templates in the `keycaps` directory (more details needed)

## Stuff to Do
* Program the Teensy 4.0 microcontroller with the Arduino sketch in the `Arduino/K130` directory
* Solder in the diodes on the matrix PCB **first**
* Insert the stabilizers into the aluminum mounting plate
* Insert the keyswitches into the aluminum mounting plate and matrix PCB
* Double check with a multimeter that all the keyswitches work!
* Only **after** checking the keyswitches solder them to the matrix PCB!
* Assemble the encoder board
* Solder the matrix board to the encoder board **last**
* Install the keycaps
* Check that the keyboard works
* Assemble the keyboard case
