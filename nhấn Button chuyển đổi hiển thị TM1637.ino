#include <TM1637Display.h>

// define the connections pins
#define CLK 9
#define DIO 10

TM1637Display display = TM1637Display(CLK, DIO);
//----------------------
#include <ezButton.h>
ezButton button(7); 
//-----------------------
#include <RTClib.h>
RTC_DS3231 rtc;

void setup() {
  display.clear();
  display.setBrightness(7); 
  button.setCountMode(COUNT_FALLING);
if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1);
  }
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}
void loop(){
  
  button.loop();
  
  unsigned long count = button.getCount();
  DateTime now = rtc.now();
  long lan_1 = now.hour()*100+now.minute();
  long lan_2 = now.day()*100+now.month();
  long lan_3 = now.year();
  
   if(count == 1){
    
    display.showNumberDecEx(lan_1, 0b11100000, true, 4, 0);
    Serial.println("1");
    }
   if(count == 2){
    
    display.showNumberDecEx(lan_2, 0b11100000, false, 4, 0);
    Serial.println("2");
    }
   if(count == 3){
   
    display.showNumberDec(lan_3);
    Serial.println("3");
    }
  if(count >=3) button.resetCount();
  
  }
