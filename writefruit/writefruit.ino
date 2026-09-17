/*
ERP_ArduinoModule_bme
This Arduino sketch queries the BME280 sensor
using the Adafruit BME280 library, and prints
the measurements on Serial
The circuit:
- Arduino UNO R3 connected over serial USB
- BME280
created 11 Mar 2025
for the ERP Arduino module
*/
// Import libraries :
#include <Adafruit_BME280.h> // loads the Adafruit BME280 library and required I2C
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
Adafruit_BME280 bme; // I2C ; // Redefine sensor name to bme in this sketch
unsigned int delayT ; // Variable for time between readings
unsigned long startTime, currentTime;
float lastT , lastP , lastH ; // We will store the last recorded data
// in these variables before printing .
const int csPin = 10;
const unsigned long duration = 300000;
String FileName = "wee.txt";
File myFile;
void setup (){
Serial.begin(9600);
Serial.println(" Initializing SD card ... ");
if (!SD.begin(csPin)) {
Serial.println(" initialization failed !");
}
// Start serial connection at 9600 baud
while (!Serial); // This will freeze execution here until
// Serial returns 0, this indicates a
// Serial connection is succesfully made .
// Below we start the BME sensor . Two things happen :
// - We call bme.begin (), the value 0 x76 indicates
// the address of the BME on the I2C interface .
// The default address is 0x76, but 0x77 is the
// alternative address, enabled by soldering a jumper on
// the board.
// - bme.begin() will return a non-zero value if some error
// occurred. We store this value .
int status = bme.begin(0x76);
if (! status ){ // If the status is non-zero , we output an error messge
Serial.print (" Could not find a valid BME280 sensor , ");
Serial.print(" check wiring ! Error : ");
Serial.println(status);
while (1); // This will freeze execution at this point . If
// the sensor did not load succesfully , we don’t
// want to execute the rest of the code
}
// If we reach this point of the code , we have succesfully connected
// to the sensor , so we can display this using the Serial interface .
Serial.println(" Succesfully connected to BME280 sensor .");
myFile = SD.open(FileName, FILE_WRITE);
if(myFile) {
myFile.println("time in ms \t temparature_C \t pressure_Pa \t Humidity");
myFile.close();
}
startTime = millis();
// Finally we set the delay time in milliseconds
delayT = 5000;

}
/* Now we can move on to the loop() section . We just read all the quantities this
sensor can measure and output them to the screen . */
void loop (){
currentTime = millis();
if (currentTime - startTime >=duration){
  Serial.print("Logging finished");
  while(1){
  }
}
myFile = SD.open(FileName, FILE_WRITE);

// By using the library , life becomes easy , as promised
lastT = bme.readTemperature(); // Temperature
lastP = bme.readPressure(); // Pressure
lastH = bme.readHumidity(); // Relative Humidity
// Output everything over the Serial connection
// Output to serial plotter

if (myFile) {
myFile.print(currentTime-startTime);
myFile.print("\t");
myFile.print(lastT);
myFile.print("\t");
myFile.print(lastP);
myFile.print("\t");
myFile.println(lastH);
// close the file
myFile.close();
} else {
// if the file didn ’t open , print an error message :
Serial.println(" error opening file for writing ");
}
// Delay time until next loop
delay(delayT);


// Re - open the file for reading :
/*
myFile = SD.open(FileName);
if (myFile) {
Serial.println(" Data in file " + FileName);
// read from the file until there ’s nothing else in it:
while (myFile.available()) {
Serial.write(myFile.read());
}
// close the file :
myFile.close();*/
}

