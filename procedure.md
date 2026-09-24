# Le procedure

## Brief outline

* Install arduino IDE on your system.
* Connect arduino to arduino IDE via USB.
* Install blink.c test script onto arduino.
* Check if L led blinks every second.

* CO2 sensor connections.
    * Stick it in the breadboard column g rows 1-7 with the wire going out to the left. (yellow should be in row 7)
    * Color coding plus connections (breadboard, Arduino): (4 (red) ,+5V), (3 (black), gnd), (5 (blue), digital pin7), (green , digital pin 6).
* SD card connection.
    * Stick it in the breadboard (10,11,12,13,14,15).
    * Connections (10, gnd), (11, +5V), (12 (MISO), digital pin 12), (13 (MOSI), digital pin 11), (14 (SCLK), digital pin 13), (15 (CS), digital pin 10).
* Install co2.c script onto arduino.
* Read out serial output.
* Read out sd card.
* Put sd card in your laptop wth the usb adapter
* Read out data using the co2_plot.py file
