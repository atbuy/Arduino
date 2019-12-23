#include <RH_ASK.h> // include Radio head Amplitude Shift Keying Library
#include <SPI.h> // include depensant SPI library  (serial perefferal library)

RH_ASK rf_driver(2000, 2, 4, 5);

void setup() {
  rf_driver.init();  // Initialize ASK object
  
}

void loop() {
 // Set buffer size of the expected message
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);
  
  // Check if the received packet is the correct size
  if (rf_driver.recv(buf, &buflen)) {
    Serial.print("Message Received: ");
    Serial.println((char*)buf);
  }

}
