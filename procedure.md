# Le procedure

## Brief outline

* Install arduino IDE on your system.
* Connect arduino to arduino IDE via USB.
* Install blink.c test script onto arduino.
* Check if L led blinks every second.

* CO2 sensor connections.
    * Stick it in the breadboard (1,2,3,4).
    * Color coding: red +5V, black gnd, blue 7 (RX on sensor side), green 6 (TX on sensor side).
* SD card connection.
    * Stick it in the breadboard (10,11,12,13,14,15).
    * Connections (10, gnd), (11, +5V), (12 (MISO), pin 12), (13 (MOSI), pin 11), (14 (SCLK), pin 13), (15 (CS), pin 10).
* Install co2.c script onto arduino.
* Read out serial output.
* Read out sd card.
