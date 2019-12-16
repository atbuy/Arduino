#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3);
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);

  sendCommand("AT");
  sendCommand("AT+ROLE0");
  sendCommand("AT+UUID0XFF00");
  sendCommand("AT+CHAR0XFF01");
  sendCommand("AT+NAMELightBlue");

  motor1.setSpeed(255);
  motor1.run(RELEASE);
  delay(20);
  motor2.setSpeed(255);
  motor2.run(RELEASE);
  delay(20);
  motor3.setSpeed(255);
  motor3.run(RELEASE);
  delay(20);
  motor4.setSpeed(255);
  motor4.run(RELEASE);
  delay(20);
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
void sendCommand(const char * command) {
  Serial.print("Command Sent: ");
  Serial.println(command);
  mySerial.println(command);
  delay(100);

  char reply[100];
  int i=0;
  while (mySerial.available()) {
    reply[i] = mySerial.read();
    delay(50);
    i += 1;
  }
  reply[i] = '\0';
  delay(100);
  Serial.print(reply);
  Serial.println("Reply successful");
}

String readSerial() {
  char reply[50];
  int i=0;
  while (mySerial.available()) {
    reply[i] = mySerial.read();
    i += 1;
  }
  reply[i] = "\0";
  if (strlen(reply) > 0) {
    Serial.println(reply);
    Serial.println("We have a signal!");
    return reply;
  }
}
void writeSerialToBLE(int value) {
  mySerial.println(value);
}

void writeToBLE(char value) {
  Serial.print("Writing hex: ");
  Serial.println(value, HEX);
  mySerial.write(value);
}
String ble_val;

void loop() {
  ble_val = readSerial();
  delay(100);
  if (ble_val.startsWith("fwd")) {
    GO();
    delay(2000);
    STOP();
    delay(500);
  }
  else if (ble_val.startsWith("rvrs")) {
    REVERSE();
    delay(2000);
    STOP();
    delay(500);
  }
  else if (ble_val.startsWith("ri")) {
    fastRight();
    delay(750);
    STOP();
    delay(500);
  }
  else if (ble_val.startsWith("l")) {
    fastLeft();
    delay(750);
    STOP();
    delay(500);
  }
  else if (ble_val.startsWith("stop")) {
    STOP();
    delay(500);
  }
  ble_val = "stop";
  delay(100);
  delay(500);

}
