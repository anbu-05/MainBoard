#include <Arduino.h>
//#include <HardwareSerial.h>

// HardwareSerial UART2(1); //UART2

uint8_t i = 0;

void setup() {
  Serial.begin(115200);
  // UART2.begin(115200, SERIAL_8N1, 16, 17); 
}

void loop() {
  if (Serial.available() > 0) {
    i = Serial.read();

    Serial.print("received: ");
    Serial.println(i);
  }
}