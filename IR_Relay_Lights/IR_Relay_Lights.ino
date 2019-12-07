#include <IRremote.h>

const int relay = 8;
const int pinIR = 9;

IRrecv irrecv(pinIR);
decode_results results;

void setup() {
  pinMode(relay, OUTPUT);
  digitalWrite(relay, LOW);

  irrecv.enableIRIn(); // Start the IR receiver
}

int opened = 0;

void loop() {
  if (irrecv.decode(&results)) {
    if (opened == 1 and (results.value == 16738455 or results.value == 551489775)) {
      digitalWrite(relay, HIGH);
      opened = 0;
      delay(15);
    }
    else if (opened == 0 and (results.value == 16738455 or results.value == 551489775)) {
      digitalWrite(relay, LOW);
      opened = 1;
      delay(15);
    }
    irrecv.resume();
  }
}
