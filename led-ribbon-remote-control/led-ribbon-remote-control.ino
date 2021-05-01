#include "remotecontrol.h"

#define IR_SEND_PIN 2

void setup() {
  Serial.begin(9600);
  initRemoteControl(IR_SEND_PIN);
}

void loop() {
  sendSignal(BUTTON_ON);
  delay(10000);
}
