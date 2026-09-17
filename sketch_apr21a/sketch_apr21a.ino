/*
sketch_code_example
Write here what your code does.
For example, in this sketch, we calculate the table of an integer (7 by default) 10 times,
or until the maximum value is reached (50 by default), after which the code ends in
an infinite empty loop. The output is printed on serial.
The circuit:
- Arduino UNO R3 connected over serial USB
created 10 Mar 2025
for the ERP Arduino module
*/
// Load libraries (often required for specific commands)
#include <SoftwareSerial.h> // Library to use serial input and output
// Define global variables
float NUMBER = 4.5; // Table of this integer
int MAXVAL = 100; // Integer maximum result of calculation
char TOOHIGH = "Exceeded, quitting... "; // String displayed when max is exceeded
const unsigned long BAUD_RATE = 9600;
// Setup definitions
void setup() {
// sets the baud rate (bits per second) of data transfer over serial connection to your PC
Serial.begin(BAUD_RATE);
// Print to Serial Monitor, quotes " " indicate string
Serial.print("The table of " + String(NUMBER));
Serial.print("\n"); // New line character
} // end of setup
void loop() {
float k; // local variable
Serial.println("give a number for which to calculate the table");
while(Serial.available() == 0){
}

if(Serial.available()>0){
  NUMBER = Serial.parseInt();
  Serial.read();
}
Serial.println("give a maximum value to display");
while(Serial.available() ==0 ){
}

if(Serial.available() >0){
  MAXVAL = Serial.parseInt();
  Serial.read();
}
for (float j = 1; j <= 10; j++) { // for loop with local variable j running from 1 to 10
k = Mult(NUMBER, j); // user-defined function ( see code at end of sketch )
if (k <= MAXVAL) { // If k does not exceed the maximum value, give the result
// prints a line ending with a new line character
Serial.println(String(j) + " times " + String(NUMBER) + " = " + String(k));
delay(500); // Pause of 500 ms between each output
}
else { // If k exceeds the maximum value, exit the loop
Serial.println(TOOHIGH);
break;
}
} // end of for loop
Serial.println("Ready");
} // end of main loop
// User-defined functions
/* Our function Mult takes as input two integers and
gives the multiplication of the two as output
*/
float Mult(float x, float y) {
float result = x * y;
return result;
}