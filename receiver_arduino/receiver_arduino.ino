#include <RH_ASK.h>
#include <SPI.h>

RH_ASK rf_driver(2000, 2, 4, 5);

void setup() {
  rf_driver.init();
  //rf_driver.setModeIdle();
  Serial.begin(9600);

}

int msg_num = 0;
void loop() {
  msg_num++;
  const char *msg = "HELLLLOOO!";
  rf_driver.send((uint8_t *)msg, strlen(msg));
  Serial.print("Sending message: ");
  Serial.println(msg);
  rf_driver.waitPacketSent();
  delay(200);
  /*
  // Set buffer size of the expected message
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);
  
  // Check if the received packet is the correct size
  if (rf_driver.recv(buf, &buflen)) {
    Serial.print("Message Received: ");
    Serial.println((char*)buf);
  }
  */ 
  
}
