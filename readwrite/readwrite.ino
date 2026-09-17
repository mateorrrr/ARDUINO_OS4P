/*
* The circuit :
* SD card attached to SPI bus as follows :
MOSI - pin 11 |
MISO - pin 12 | These pins are connected to the hardware SPI -bus
CLK - pin 13 |
CS - pin 10 - Chip Select pin can be chosen freely ; default is pin 10
See https://www.arduino.cc/en/reference/board
*/
#include <SPI.h>
#include <SD.h>
// "const" means constant: this value will not change while running
// This will allow the compiler to optimize
const int csPin = 10;
String FileName = "data.txt";
File myFile;
void setup() {
// Open serial communications and wait for port to open :
Serial.begin(9600);
Serial.println(" Initializing SD card ... ");
if (!SD.begin(csPin)) {
Serial.println(" initialization failed !");
return;
}
Serial.println(" initialization done .");
}
void loop() {
// Open the file for writing
myFile = SD.open(FileName, FILE_WRITE);
// If the file opened all right , write to it:
if (myFile) {
Serial.println("Writing to " + FileName);
myFile.println("testing 1, 2, 3.");
// close the file
myFile.close();
Serial.println(" Writing to file done !");
} else {
// if the file didn ’t open , print an error message :
Serial.println(" error opening file for writing ");
}
// Re - open the file for reading :
myFile = SD.open(FileName);
if (myFile) {
Serial.println(" Data in file " + FileName);
// read from the file until there ’s nothing else in it:
while (myFile.available()) {
Serial.write(myFile.read());
}
// close the file :
myFile.close();
while (1) {}
} else {
// if the file didn ’t open , print an error message :
Serial.println(" error opening file for reading ");
}
// // This segment of code allows you to remove the file
// int rem = SD.remove(FileName);
// // this removes the file
// Serial.print(" removing file, status : ");
// Serial.println(rem);
}