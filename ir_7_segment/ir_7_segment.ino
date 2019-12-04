#include <LiquidCrystal_I2C.h>
#include <IRremote.h>

const int E = 13;
const int D = 12;
const int C = 11;
const int DP = 10;
const int B = 9;
const int A = 8;
const int F = 7;
const int G = 6;

const int pinIR = 5;

LiquidCrystal_I2C lcd(0x27, 16, 2);

IRrecv irrecv(pinIR);
decode_results results;

void setup() {
  lcd.begin();  // Start the lcd 
  lcd.clear();  // Clear the lcd's screen

  irrecv.enableIRIn();  // Start the IR receiver
  
  pinMode(E, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(DP, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);

  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(DP, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);

}

void loop() {
  if (irrecv.decode(&results) {
    /* Prints "0" on the 7-Segment Display */
    if (irrecv == /* IR VALUE */ ) {   // Button "0"
      segWrite(1,1,1,0,1,1,1,0);
      irrecv.resume();
    }
    
    /* Prints "1" on the 7-Segment Display */
    if (irrecv == 16724175) {   // Button "1"
      segWrite(0,0,1,0,1,0,0,0);
      irrecv.resume();
    }
    
    /* Prints "2" on the 7-Segment Display */
    if (irrecv == 16718055) {   // Button "2"
      segWrite(1,1,0,0,1,1,0,1);
      irrecv.resume();
    }
    
    /* Prints "3" on the 7-Segment Display */
    if (irrecv == 16743045) {   // Button "3"
      segWrite(0,1,1,0,1,1,0,1);
      irrecv.resume();
    }
    
    /* Prints "4" on the 7-Segment Display */
    if (irrecv == /* IR VALUE */) {   // Button "4"
      segWrite(0,0,1,0,1,0,1,1);
      irrecv.resume();
    }

    /* Prints "5" on the 7-Segment Display */
    if (irrecv == /* IR VALUE */) {   // Button "5"
      segWrite(0,1,1,0,0,1,1,1);
      irrecv.resume();
    }

    /* Prints "6" on the 7-Segment Display */
    if (irrecv == /* IR VALUE */) {   // Button "6"
      segWrite(1,1,1,0,0,1,1,1);
      irrecv.resume();
    }

    /* Prints "7" on the 7-Segment Display */
    if (irrecv == /* IR VALUE */) {   // Button "7"
      segWrite(0,0,1,0,1,1,1,0);
      irrecv.resume();
    }

    /* Prints "8" on the 7-Segment Display */
    if (irrecv == /* IR VALUE */) {   // Button "8"
      segWrite(1,1,1,0,1,1,1,1);
      irrecv.resume();
    }

    /* Prints "9" on the 7-Segment Display */
    if (irrecv == /* IR VALUE */) {   // Button "9"
      segWrite(0,1,1,0,1,1,1,1);
      irrecv.resume();
    }

    /* Removes the dot from the 7-Segment Display */
    if (irrecv == 16769055) {   // Button "-"
      digitalWrite(DP, LOW);
      irrecv.resume();
    }

    /* Adds the dot to the 7-Segment Display */
    if (irrecv == 16754775) {   // Button "+"
      digitalWrite(DP, HIGH);
      irrecv.resume();
    }

    /* Writes "Off" on the LCD Screen */
    if (irrecv == /* IR VALUE */) {   // Button "CH-"
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Off");
      delay(200);
      irrecv.resume();
    }

    /* Writes "On" on the LCD Screen */
    if (irrecv == /* IR VALUE */) {   // Button "CH+"
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("On");
      delay(200);
      irrecv.resume();
    }

    /* Clears the 7-Segment Display */
    if (irrecv == 16748655) {   // Button "EQ"
      segWrite(0,0,0,0,0,0,0,0);
      irrecv.resume();
    }
    
    /* Clears the LCD Screen*/
    if (irrecv == /* IR VALUE */) {   // Button "CH"
      lcd.clear();
      irrecv.resume();
    }
  }

}

void segWrite(int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8) {
    if (v1 == 1) {
      digitalWrite(E, HIGH);
    }
    else if (v1 == 0) {
      digitalWrite(E, LOW);
    }
    if (v2 == 1) {
      digitalWrite(D, HIGH);
    }
    else if (v2 == 0) {
      digitalWrite(D, LOW);
    }   
    if (v3 == 1) {
      digitalWrite(C, HIGH);
    }
    else if (v3 == 0) {
      digitalWrite(C, LOW);
    }
    if (v4 == 1) {
      digitalWrite(DP, HIGH);
    }
    else if (v4 == 0) {
      digitalWrite(DP, LOW);
    }
    if (v5 == 1) {
      digitalWrite(B, HIGH);
    }
    else if (v5 == 0) {
      digitalWrite(B, LOW);
    }
    if (v6 == 1) {
      digitalWrite(A, HIGH);
    }
    else if (v6 == 0) {
      digitalWrite(A, LOW);
    }
    if (v7 == 1) {
      digitalWrite(F, HIGH);
    }
    else if (v7 == 0) {
      digitalWrite(F, LOW);
    }
    if (v8 == 1) {
      digitalWrite(G, HIGH);
    }
    else if (v8 == 0) {
      digitalWrite(G, LOW);
    }

}
