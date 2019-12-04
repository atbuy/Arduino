#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pinWater = 0;
int waterLvl;

void setup() {
  // put your setup code here, to run once:
  lcd.clear();
  lcd.begin();
  delay(250);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  waterLvl = analogRead(pinWater);
  //lcd.setCursor(0,0);
  //lcd.println(waterLvl);
  if (waterLvl > 200 and waterLvl < 230) {
    lcd.clear();
    lcd.print("Low Level");
    lcd.setCursor(0,1);
    delay(200);
    while (waterLvl > 200 and waterLvl < 230) {
      lcd.print(waterLvl);
      waterLvl = analogRead(pinWater);  
      lcd.setCursor(0,1);
      lcd.print("");
      delay(500);
    }
  }
  else if (waterLvl > 230 and waterLvl < 290) {
    lcd.clear();
    lcd.print("Medium Level");
    lcd.setCursor(0,1);
    delay(200);
    while (waterLvl > 230 and waterLvl < 290) {
      lcd.print(waterLvl);
      waterLvl = analogRead(pinWater);
      lcd.setCursor(0,1);
      lcd.print("");
      delay(500);
    }
  }
  else if (waterLvl > 290) {
    lcd.clear();
    lcd.print("High Level");
    lcd.setCursor(0,1);
    delay(200);
    while (waterLvl > 260) {
      lcd.print(waterLvl);
      waterLvl = analogRead(pinWater);
      lcd.setCursor(0,1);
      lcd.print("");
      delay(500);
    }
    
  }

}
