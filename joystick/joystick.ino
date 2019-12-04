const int pinX = 0;  // analog pin for x axis of joystick
const int pinY = 1;  // analog pin for y axis of joystick
const int SW = 13;  // pin for press of joystick

const int RED = 10;  // pin for red in rgb led
const int GREEN = 9;  // pin for green in rgb led
const int BLUE = 8; // pin for blue in rgb led

const int pinBuzz = 12;  // pin for buzzer

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(SW, INPUT);
  pinMode(pinBuzz, OUTPUT);

  digitalWrite(SW, HIGH);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
}

void loop() {
  int x_axis = analogRead(pinX);
  int y_axis = analogRead(pinY);
  int SW_key = digitalRead(SW);
   
  if  (SW_key == 0) {
    setColor(0, 0, 0);
    delay(50);
    while (SW_key == 0) {
      tone(pinBuzz, 1000, 50);
      SW_key = digitalRead(SW);
    }
    
  }
  else if (x_axis == 0) {
    setColor(255, 0, 0);
  }
  else if (x_axis == 1023) {
    setColor(0, 255, 0);
  }
  else if (y_axis == 0) {
    setColor(0, 0, 255);
  }
  else if (y_axis == 1023) {
    setColor(200, 0, 100);
  }
  else {
    setColor(255, 255, 255);
  }
}


void setColor(int red, int green, int blue) {
  digitalWrite(RED, red);
  digitalWrite(GREEN, green);
  digitalWrite(BLUE, blue);
}
