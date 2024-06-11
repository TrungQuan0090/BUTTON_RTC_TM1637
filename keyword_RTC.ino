#include <RTClib.h>

RTC_DS3231 rtc;

void setup(){

  if (! rtc.begin()) {
  Serial.println("Couldn't find RTC");
  while (1);
    
  }
}
void loop()
{

...
}
