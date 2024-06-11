#include <RTClib.h>

RTC_DS3231 rtc;

void setup(){

  if (! rtc.begin()) {
  Serial.println("Couldn't find RTC");
  while (1);
  
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    
  }
}
void loop()
{
  DateTime now = rtc.now();
  
  long ngay = now.day();
  long thang = now.month();
  long nam = now.year();
  
  long gio = now.hour();
  long phut = now.minute();
  long giay = now.second();
  
}
