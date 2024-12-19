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
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);

  if (rf_driver.recv(buf, &buflen)) {
    buf[buflen] = '\0'; // Null-terminate the received data
    Serial.print("Received: ");
    Serial.println((char*)buf); // Print the received message
  }
}
