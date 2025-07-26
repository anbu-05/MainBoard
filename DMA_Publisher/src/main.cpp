#include <Arduino.h>
// #include <HardwareSerial.h>

// HardwareSerial UART2(2); //UART2

uint8_t i = 0;

void setup() {
  Serial.begin(115200);
  // UART2.begin(115200, SERIAL_8N1, 16, 17); 
}

void loop() {
  //Serial.print("message sent ");
  Serial.write(i);
  // UART2.println(i);
  i++;
  delay(500);
}

