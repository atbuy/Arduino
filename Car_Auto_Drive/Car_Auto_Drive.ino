#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  motor1.setSpeed(255);
  motor1.run(RELEASE);

  motor2.setSpeed(255);
  motor2.run(RELEASE);
  
  motor3.setSpeed(255);
  motor3.run(RELEASE);
  
  motor4.setSpeed(255);
  motor4.run(RELEASE);
}

void loop() {
  GO();
  delay(2000);
  STOP();
  delay(500);
  fastRight();
  delay(750);
  STOP();
  delay(500);
  REVERSE();
  delay(2000);
  STOP();
  delay(500);
  fastLeft();
  delay(750);
  STOP();
  delay(500);
}


void GO() {
  motor1.run(FORWARD);
  delay(100);
  motor3.run(FORWARD);
  delay(100);
  motor2.run(FORWARD);
  delay(100);
  motor4.run(FORWARD);
  delay(1000);
}
void STOP() {
  motor1.run(RELEASE);
  delay(100);
  motor3.run(RELEASE);
  delay(100);
  motor2.run(RELEASE);
  delay(100);
  motor4.run(RELEASE);
  delay(1000);
}
void fastRight() {
  motor1.run(RELEASE);
  delay(100);
  motor2.run(FORWARD);
  delay(100);
  motor3.run(FORWARD);
  delay(100);
  motor4.run(RELEASE);
  delay(100);
}
void fastLeft() {
  motor1.run(FORWARD);
  delay(100);
  motor2.run(RELEASE);
  delay(100);
  motor3.run(RELEASE);
  delay(100);
  motor4.run(FORWARD);
  delay(100);
}
void REVERSE() {
  motor1.run(BACKWARD);
  delay(100);
  motor3.run(BACKWARD);
  delay(100);
  motor2.run(BACKWARD);
  delay(100);
  motor4.run(BACKWARD);
  delay(1000);
}
