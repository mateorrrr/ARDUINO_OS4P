# Open science Arduino reproducibility challenge

You will setup a CO2 measurement apparatus with which you perform a measurement of the ambient CO2 concentration in a room full of students for a specified interval of time.

## Components

Components of the setup include the following:

| Component | Image |
| --------- | ----- |
| Breadboard | [link (No malware please trust)](https://upload.wikimedia.org/wikipedia/commons/e/e8/Breadboard.png?utm_source=en.wikipedia.org&utm_campaign=imageinfo&utm_content=thumbnail_unscaled) |
| Arduino UNO | [link](https://upload.wikimedia.org/wikipedia/commons/3/38/Arduino_Uno_-_R3.jpg?utm_source=en.wikipedia.org&utm_campaign=imageinfo&utm_content=thumbnail_unscaled) |
| CO2 sensor | [link](https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fwww.botnroll.com%2F21927-large_default%2Fwinsen-mh-z19c-co2-sensor-with-cable.jpg&f=1&nofb=1&ipt=10ed8bd70c819ad0ab7978335d395197fe17f269c700d80d55f9eb7a0ee74060&ipo=images) |
| SD card reader (with SD card included) | [link](https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Ftse4.mm.bing.net%2Fth%2Fid%2FOIP.1Y9Ex3qN4S4y6_ZWluWbHwHaHa%3Fr%3D0%26pid%3DApi&f=1&ipt=7cfc39f92f947aa61bf41d738847c1998df4a66d627a05f34e86381c86d29f47&ipo=images) |

> and some components are in the package but not used:
>  
> | Component | Image |
> | --------- | ----- |
> | P/T/RH sensor | [link](https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fm.media-amazon.com%2Fimages%2FI%2F61Co4r%2Bqy5L._SL1500_.jpg&f=1&nofb=1&ipt=d261b961b2043d599b7c832e59057505fbe41bff190feb66e74d9109c02d82f5&ipo=images) |
> | Powerbank | Identification picture trivial |

## Getting started 

* Install Arduino IDE on your system.
* Connect to Arduino UNO in Arduino IDE via USB.
* Install `blink.c` test script onto the Arduino.
* Check if L led blinks every second.
* If it does not blink, either the Arduino is broken or your arduino IDE is not in the default settings.

## Setting up the measurement apparatus

We will make use of the grid coding of the breadboard, so make sure to orient it accordingly.

### Connecting the CO2 sensor

* Stick the pins of the CO2 sensor into the breadboard in g1-7 (thus vertically) with the wires to the CO2 sensor going out to the left (or equivalently yellow should be in g7). 
* Now make with the supplied wires the following connections (breadboard, Arduino): (i4 (red) ,+5V), (i3 (black), gnd), (i5 (blue), digital pin 7), (i6 (green) , digital pin 6).

### Connecting the SD card reader

* Stick the pins of the SD card reader into the broadboard g10-15 with gnd on g10. 
* Now make the following connections (breadboard, Arduino): (i10 (gnd), gnd), (i11 (vcc), +5V), (i12 (MISO), digital pin 12), (i13 (MOSI), digital pin 11), (i14 (SCLK), digital pin 13), (i15 (CS), digital pin 10). 

### Installing the software

* Install `CO2_sensor.c`onto the Arduino.
* Read out the serial output (baud 9600), messages should say everything is fine. 

> If things are not fine, then the explicit error message could help you further to fix your potential wiring mistakes. If you did not make any wiring mistakes consider the components broken and give up.

## Performing the measurement

* I guess you are now in a room with CO2 exhaling humanoids around you, I also guess that this room has some means of ventilation, rendering any CO2 buildup negligible. Making a very boring measurement scenario, essentially measuring noise. Yet this is what you will do, power the Arduino with your laptop for about 40 minutes while you do something useful with your life. 
* After these 40 minutes you throw the SD card in the SD card reader of your laptop, or phone, or fax, whatever works for you, and copy the `DATA.csv` file into your python environment folder. 

## Visualisation of the measurement

* Throw `plot_CO2.py` into your python environment folder and execute it. `CO2_plot.png` will now emerge in your folder. Compare it with our result. Does it also contain mostly noise?

