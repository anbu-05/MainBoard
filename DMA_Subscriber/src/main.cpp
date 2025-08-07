#include <Arduino.h>
//#include <HardwareSerial.h>

// HardwareSerial UART2(1); //UART2

uint8_t i = 0;

uint8_t msg_type = 0x11;
uint16_t msg_ID = 0x4321;

void setup() {
  Serial.begin(115200);
  // UART2.begin(115200, SERIAL_8N1, 16, 17); 
}

void loop() {

  Serial.write(msg_type);
  Serial.write(msg_ID);
  Serial.write(msg_ID >> 8);

  while (Serial.available() > 0) {
    i = Serial.read();

    Serial.print("received: ");
    Serial.write(i);
    Serial.println();
  }
  delay(2000);
}