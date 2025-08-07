#include <Arduino.h>
// #include <HardwareSerial.h>

// HardwareSerial UART2(2); //UART2

uint8_t i = 0;


struct Message_t {
  uint8_t type;
  uint16_t ID;
  uint8_t data[64];
};


Message_t msg;

void setup() {
  Serial.begin(115200);
  // UART2.begin(115200, SERIAL_8N1, 16, 17); 
  msg.type = 0x10;
  msg.ID = 0x4321;
}

void loop() {

  // for (int i=0;i<32;i++) {
  //   msg.data[i] = random(100);
  // }

  msg.data[0] = 10;
  msg.data[10] = 20;
  msg.data[20] = 30;
  msg.data[30] = 40;

  Serial.write((uint8_t*)&msg, sizeof(msg));
  delay(500);
}

