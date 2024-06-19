#include <RH_ASK.h>
#include <SPI.h>

RH_ASK rf_driver;

void setup() {
  Serial.begin(9600); // Initialize Serial Communication
  if (!rf_driver.init()) {
    Serial.println("RF driver initialization failed");
  }
}

void loop() {
  const char* message = "Hello"; // Message to be transmitted
  Serial.println("Transmitting: ");
  Serial.println(message);
  
  rf_driver.send((uint8_t *)message, strlen(message)); // Send the message
  rf_driver.waitPacketSent();
  
  delay(20); // Wait for a second before sending the next message
}
