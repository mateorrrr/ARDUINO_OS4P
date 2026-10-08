#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>
const int chipSelect = 10;
#define MH_Z19_RX 6
#define MH_Z19_TX 7
const int statusLed = 13;
const int time_step = 10000;
SoftwareSerial co2Serial(MH_Z19_RX, MH_Z19_TX);
byte cmd[] = {0xFF, 0x01, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x79};
unsigned char response[9];
File myFile;
unsigned long lastLogTime = 0;
int lineCounter = 1;
void setup() {
 Serial.begin(9600);

 pinMode(statusLed, OUTPUT);
 Serial.println("--- SYSTEM STARTUP ---");
 Serial.print("Initializing SD card... ");
 if (!SD.begin(chipSelect)) {
 Serial.println("FAILED!");
 while (1);
 }
 Serial.println("SUCCESS!");
 if (!SD.exists("data.csv")) {
 myFile = SD.open("data.csv", FILE_WRITE);
 if (myFile) {
 myFile.println("Time (seconds),CO2 (ppm)");
 myFile.close();
 Serial.println("Created new data.csv file.");
 }
 } else {
 Serial.println("Found existing data.csv file.");
 }
 co2Serial.begin(9600);
 Serial.println("Ready! Starting loop...\n");
}
void loop() {
 if (millis() - lastLogTime >= time_step) {
 lastLogTime = millis();
 Serial.print("[Loop] Requesting CO2 data... ");
 while(co2Serial.available()) { co2Serial.read(); }

 co2Serial.write(cmd, 9);
 delay(150);
 int availableBytes = co2Serial.available();
 Serial.print("Bytes received: ");
 Serial.print(availableBytes);
 Serial.print(" / 9. ");
 if (availableBytes >= 9) {
 for (int i = 0; i < 9; i++) {
 response[i] = co2Serial.read();
 }
 if (response[0] == 0xFF && response[1] == 0x86) {
 int co2ppm = (response[2] << 8) + response[3];

 int secondsPassed = lineCounter * (time_step / 1000);
 Serial.print("CO2: ");
 Serial.print(co2ppm);
 Serial.print(" ppm. Writing to SD... ");
 myFile = SD.open("data.csv", FILE_WRITE);
 if (myFile) {
 myFile.print(secondsPassed);
 myFile.print(",");
 myFile.println(co2ppm);
 myFile.close();

 lineCounter++;
 Serial.println("DONE!");
 digitalWrite(statusLed, HIGH);
 delay(150);
 digitalWrite(statusLed, LOW);
 } else {
 Serial.println("SD WRITE ERROR!");
 }
 } else {
 Serial.println("ERROR: Bad data packet headers!");
 }
 } else {
 Serial.println("TIMEOUT: Sensor didn't reply in time.");
 }
 }
}
