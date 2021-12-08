#include <Wire.h>
#include "RTC_DS1307.h"

const int horloge = 8;
void setup() {
   Wire.begin();
   Serial.begin(9600);

}

void loop() {
   Serial.print ("myTime : ");
   // 
   Wire.beginTransmission(horloge);
   Wire.endTransmission();
   Wire.requestFrom(8, 8);
   char c = Wire.read();
   Serial.print (c);
   Serial.print ("\n");

   delay(500);
}
