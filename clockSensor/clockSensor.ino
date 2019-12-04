#include <DS1302.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int secs = 55;
DS1302 rtc(2, 3, 4);
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pinBuzz = 12;


void setup() {
  Serial.begin(9600);
  pinMode(pinBuzz, OUTPUT);
  
  lcd.begin();
  lcd.backlight();
  
  rtc.halt(false);
  rtc.writeProtect(false);
  rtc.setDOW(FRIDAY);   
  rtc.setTime(06, 59, secs);     
  rtc.setDate(29, 11, 2019);
}

void loop() {
  Serial.println(rtc.getTimeStr());
  if (secs == "00") {
    Serial.println("it's 7 o' clock");
    //lcd.clear();
    //lcd.print("It's 7 o'clock");
    delay(1000);
    
    /*
    for (int i = 0; i <= 5; i += 1) {
      digitalWrite(pinBuzz, HIGH);
      tone(pinBuzz, 1000, 10000);
      delay(2000);
      digitalWrite(pinBuzz, LOW);
    }
    */
  }
  
  lcd.setCursor(4, 0);
  lcd.print(rtc.getTimeStr());
  Serial.println(rtc.getTimeStr(FORMAT_SHORT));
  
  lcd.setCursor(0, 1);
  lcd.print(rtc.getDOWStr(FORMAT_SHORT));
  Serial.println(rtc.getDOWStr(FORMAT_SHORT));
  
  lcd.setCursor(6, 1);
  lcd.print(rtc.getDateStr());
  Serial.println(rtc.getDateStr());
  delay (1000);

  
  
  

}
