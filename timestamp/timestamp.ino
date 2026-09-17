// Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include "RTClib.h"
RTC_DS3231 rtc;
void setup () {
Serial.begin(9600);
if (! rtc.begin()) {
Serial.println("Couldn’t find RTC");
Serial.flush();
while (1) delay(10);
}
if (rtc.lostPower()) {
// When time needs to be set on a new device, or after a power loss, the
// following lines sets the RTC to the date & time from the user input through Serial
Serial.println("RTC lost power! Please enter the current date and time in format YYYY MM DD HH MM SS:");
while (!Serial.available());
int year, month, day, hour, minute, second;
while (Serial.available() < 19); // Wait for full input
year = Serial.parseInt();
month = Serial.parseInt();
day = Serial.parseInt();
hour = Serial.parseInt();
minute = Serial.parseInt();
second = Serial.parseInt();
rtc.adjust(DateTime(year, month, day, hour, minute, second));
Serial.println("RTC time set successfully.");
}
}
void loop () {
DateTime now = rtc.now();
int year = now.year() ;
int month = now.month();
int day = now.day();
int hour = now.hour();
int minute = now.minute();
int second = now.second();
char time[30];
snprintf(time, sizeof(time), "%04d-%02d-%02d %02d:%02d:%02d",
year, month, day, hour, minute, second);
Serial.print(" ISO 8601 time: ");
Serial.println(time);
Serial.print(" UNIX time: ");
Serial.println(now.unixtime());
Serial.print(" Temperature: ");
Serial.print(rtc.getTemperature());
Serial.println(" C");
delay(1000);
}