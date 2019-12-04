#include <IRremote.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  //  define the lcd screen

int pinIR = 11;  //  define what pin the IR reads
int irVal;  //  define an integer to store the ir values
int RED = 6;  //  define the pin for the red color of the rgb led
int GREEN = 5;  //  define the pin for the green color of the rgb led
int BLUE = 3;  //  define the pin for the blue color of the rgb led

IRrecv irrecv(pinIR);  //  define the IR sensor
decode_results results;  // way to get the results??

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  
  lcd.begin();  //  Start the lcd 
  lcd.clear();  // Clear the lcd screen
  lcd.backlight();
  irrecv.enableIRIn();  //  Start the IR sensor
}

void loop() {
  //  Get the Results
  if (irrecv.decode(&results)){
    // If the '+' button is pushed, prints on lcd 'On'
    if (results.value == 16754775) {
      lcd.setCursor(0,0);
      lcd.clear();
      lcd.print("On");
      delay(200);
      irrecv.resume();
    }
    // If the '-' button is pushed, prints on lcd 'Off'
    else if (results.value == 16769055) {
      lcd.setCursor(0,1);
      lcd.clear();
      lcd.print("Off");
      delay(200);
      irrecv.resume();
    }
    // If the '1' button is pushed, makes the rgb led Red
    else if ( results.value == 16724175) {
      setColor(255, 0, 0);
      delay(200);
      irrecv.resume();
    }
    // If the '2' button is pushed, makes the rgb led Green
    else if (results.value == 16718055) {
      setColor(0, 255, 0);
      delay(200);
      irrecv.resume();
    }
    // If the '3' button is pushed, makes the rgb led Blue
    else if (results.value == 16743045) {
      setColor(0, 0, 255);
      delay(200);
      irrecv.resume();
    }
    // If the 'EQ' button is pushed, clears the lcd screen
    else if (results.value == 16748655) {
      lcd.clear();
      delay(200);
      irrecv.resume();
    }
  }
}

void setColor(int red, int green, int blue) {
  digitalWrite(RED, red);
  digitalWrite(GREEN, green);
  digitalWrite(BLUE, blue);
}
