#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pinLed = 13;

void setup() {
  Serial.begin(9600);
  lcd.begin();
  
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, LOW);
}

int val;
int val2;
String num = "";
String num2 = "";
String op = "";
int tot;

void loop() {
    val = Serial.read();
    delay(300);
    if (val == 49) {
      lcd.print("1");
      num += "1";
    }
    else if (val == 50) {
      lcd.print("2");
      num += "2";
    }
    else if (val == 51) {
      lcd.print("3");
      num += "3";
    }
    else if (val == 52) {
      lcd.print("4");
      num += "4";
    }
    else if (val == 53) {
      lcd.print("5");
      num += "5";
    }
    else if (val == 54) {
      lcd.print("6");
      num += "6";
    }
    else if (val == 55) {
      lcd.print("7");
      num += "7";
    }
    else if (val == 56) {
      lcd.print("8");
      num += "8";
    }
    else if (val == 57) {
      lcd.print("9");
      num += "9";
    }
    else if (val == 43) {
      lcd.print("+");
      op = "+";
      while (val2 != 48) {
        val2 = Serial.read();
        delay(300);
        if (val2 == 49) {
          lcd.print("1");
          num2 += "1";
        }
        else if (val2 == 50) {
          lcd.print("2");
          num2 += "2";
        }
        else if (val2 == 51) {
          lcd.print("3");
          num2 += "3";
        }
        else if (val2 == 52) {
          lcd.print("4");
          num2 += "4";
        }
        else if (val2 == 53) {
          lcd.print("5");
          num2 += "5";
        }
        else if (val2 == 54) {
          lcd.print("6");
          num2 += "6";
        }
        else if (val2 == 55) {
          lcd.print("7");
          num2 += "7";
        }
        else if (val2 == 56) {
          lcd.print("8");
          num2 += "8";
        }
        else if (val2 == 57) {
          lcd.print("9");
          num2 += "9";
        }
      }
    }
    else if (val == 45) {
      lcd.print("-");
      op = "-";
      while (val2 != 48) {
        val2 = Serial.read();
        delay(300);
        if (val2 == 49) {
          lcd.print("1");
          num2 += "1";
        }
        else if (val2 == 50) {
          lcd.print("2");
          num2 += "2";
        }
        else if (val2 == 51) {
          lcd.print("3");
          num2 += "3";
        }
        else if (val2 == 52) {
          lcd.print("4");
          num2 += "4";
        }
        else if (val2 == 53) {
          lcd.print("5");
          num2 += "5";
        }
        else if (val2 == 54) {
          lcd.print("6");
          num2 += "6";
        }
        else if (val2 == 55) {
          lcd.print("7");
          num2 += "7";
        }
        else if (val2 == 56) {
          lcd.print("8");
          num2 += "8";
        }
        else if (val2 == 57) {
          lcd.print("9");
          num2 += "9";
        }
      }
    }
    else if (val == 47) {
      lcd.print("/");
      op = "/";
      while (val2 != 48) {
        val2 = Serial.read();
        delay(300);
        if (val2 == 49) {
          lcd.print("1");
          num2 += "1";
        }
        else if (val2 == 50) {
          lcd.print("2");
          num2 += "2";
        }
        else if (val2 == 51) {
          lcd.print("3");
          num2 += "3";
        }
        else if (val2 == 52) {
          lcd.print("4");
          num2 += "4";
        }
        else if (val2 == 53) {
          lcd.print("5");
          num2 += "5";
        }
        else if (val2 == 54) {
          lcd.print("6");
          num2 += "6";
        }
        else if (val2 == 55) {
          lcd.print("7");
          num2 += "7";
        }
        else if (val2 == 56) {
          lcd.print("8");
          num2 += "8";
        }
        else if (val2 == 57) {
          lcd.print("9");
          num2 += "9";
        }
      }
    }
    else if (val == 42) {
      lcd.print("*");
      op = "*";
      while (val2 != 48) {
        val2 = Serial.read();
        delay(300);
        if (val2 == 49) {
          lcd.print("1");
          num2 += "1";
        }
        else if (val2 == 50) {
          lcd.print("2");
          num2 += "2";
        }
        else if (val2 == 51) {
          lcd.print("3");
          num2 += "3";
        }
        else if (val2 == 52) {
          lcd.print("4");
          num2 += "4";
        }
        else if (val2 == 53) {
          lcd.print("5");
          num2 += "5";
        }
        else if (val2 == 54) {
          lcd.print("6");
          num2 += "6";
        }
        else if (val2 == 55) {
          lcd.print("7");
          num2 += "7";
        }
        else if (val2 == 56) {
          lcd.print("8");
          num2 += "8";
        }
        else if (val2 == 57) {
          lcd.print("9");
          num2 += "9";
        }
      }
    }
    
    if (val == 61) {
      long num_ = num.toInt();
      long num2_ = num2.toInt();
      if (op == "+") {
        tot = num_ + num2_;
      }
      else if (op == "-") {
        tot = num_ - num2_;
      }
      else if (op == "*") {
        tot = num_ * num2_;
      }
      else if (op == "/") {
        tot = num_ / num2_;
      }
      lcd.print("=");
      lcd.print(tot);
      Serial.println(tot);
      delay(2000);
    }
    Serial.println(val);

}
