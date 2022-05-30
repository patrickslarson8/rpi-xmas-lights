# rpi-xmas-lights

# Problem
This project started when my spouse asked me to source a unique arragement of lights for Christmas. She wanted the lights to be Red, Green, and White. We looked but could not find any pre-made strands in this order. When comparing RGB light strands to empty strands and buying all of the bulbs, the RGB was cheaper (excluding the RGB controller....)

## First Solution
The original intent was the provide the requested color arrangement and teach myself a little about RGB strands. This only required an Arduino (actually an A Star 328PB). See the "WhiteRedGreen.ino" file for this. The Arduino is 5v and the light string 12v, so a logic level shifter was used. However, once I showed my spouse the possibilities for moving patterns and effects, she decided she wanted that instead.

## Second Solution
The second problem arose from the constant request of new light patterns. My spouse asked me to change the pattern only a couple of times before I needed a new solution. Since the controller was located in the attic, I needed a way to program the Arduino remotely, so I needed WiFi. I had a few Raspberry Pi's laying around and tried using that. This solution is ineffective as the linux OS on the RPi leads to RGB artifacts due to the way the RGB lights communicate.

## Third Solution
The next solution was to connect the arduino to the RPi and use the RPi to program the arduino with new code. This worked well enough as I could work on the code remotely and upload it to the light strand without venturing into the attic. In this configuration, the SPI pins on the RPi were used to communicate with the Arduino. The Arduino files were created on my computer, uploaded to the RPi, and uploaded to the Arduino. See the "flash-command-example.txt" for the commands used. 

## Final Solution
The last hurdle was to automatically turn off and on the lights at a set time of day. The Arduino does not have an accurate way to determine the time of day, so some sort of constant communication had to happen between the RPi and the Arduino. A USB to FTDI was used to connect the two since it included voltage shifting already. With this, the RPi could send data over the serial connection on the Arduino to control functions. The workflow for this was different as I could not get AVRdude to work with the FTDI. Instead, the arduino-cli was used to both compile the arduino files and upload them to the controller. The final hardware setup is like this:

Computer --(wifi)--> RPi --(FTDI serial)--> Arduino --(logic voltage shifter)--> RGB light strand
