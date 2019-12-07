
const int pin1 = 9;
const int pin2 = 10;
const int pin3 = 11;
const int pin4 = 12;

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
}

int step_num = 0;

void loop() {
  if (step_num == 0) {
    stepperStep(1, 0, 0, 0);
    delay(2);
  }
  else if (step_num == 1) {
    stepperStep(0, 1, 0, 0);
    delay(2);
  }
  else if (step_num == 2) {
    stepperStep(0, 0, 1, 0);
    delay(2);
  }
  else if (step_num == 3) {
    stepperStep(0, 0, 0, 1);
    delay(2);
  }
  step_num++;
  if (step_num > 3) {
    step_num = 0;
  }
}

void stepperStep(int v1, int v2, int v3, int v4){
  if (v1 == 1) {
    for (int i = 1; i < 10; i++) {
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
    }
  }
  else if (v2 == 1) {
    for (int i = 1; i < 10; i++){
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, LOW);
    }
  }
  else if (v3 == 1) {
    for (int i = 1; i < 10; i++) {
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, HIGH);
      digitalWrite(pin4, LOW);
    }
  }
  else if (v4 == 1) {
    for (int i = 1; i < 10; i++) {
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
      digitalWrite(pin3, LOW);
      digitalWrite(pin4, HIGH);
    }
  }
}
