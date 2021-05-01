#include "remotecontrol.h"
#include <IRremote.h>

#define FREQUENCY_KHZ 38
#define SIGNAL_RAW_HIGH 1600
#define SIGNAL_RAW_LOW 500

/*
 * The signal is the same for all buttons except for 10 values
 * The 'indexes' array contains the positions of the values to change
 */
unsigned int baseSignal[] = {9000,4400,600,500,600,500,550,550,600,550,550,550,600,550,600,500,600,550,550,1600,600,1600,600,1600,600,1600,600,550,550,1600,600,1600,600,1600,600,500,600,550,600,500,600,550,600,500,600,550,600,500,600,550,600,1600,600,1600,550,1600,600,1600,600,1600,600,1600,600,1600,550,1600,600};
int signalLength;
int indexes[] = {35, 37, 39, 41, 43, 51, 53, 55, 57, 59};

void initRemoteControl(int sendPin) {
  IrSender.begin(sendPin, DISABLE_LED_FEEDBACK);
  signalLength = sizeof(baseSignal) / sizeof(int);
}

void sendSignal(byte button) {
  _computeSignal(button);
  int i;
  for (int i = 0; i < signalLength; i++) {
    Serial.print(baseSignal[i]);
    Serial.print(",");
  }

  IrSender.sendRaw(baseSignal, signalLength, FREQUENCY_KHZ);
}

void _computeSignal(byte button) {
  /*
   * Value of 0 in the mask means "use LOW value" and 1 "use HIGH value"
   * Each bit position of the mask correspond to the same position index in the 'indexes' array
   */ 
  short mask = button;
  mask = (~mask << 5) | mask; // The all mask can be deduced from the position of the button on the remote control

  byte indexesLength = sizeof(indexes) / sizeof(int);
  byte i;
  for (i = 0; i < indexesLength; i++) {
    byte index = indexes[i];
    Serial.println(mask & (1 << i));
    if (mask & (1 << i)) {
      baseSignal[index] = SIGNAL_RAW_HIGH;
    } else {
      baseSignal[index] = SIGNAL_RAW_LOW;
    }
  }
}