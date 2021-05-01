#ifndef remotecontrol_h
#define remotecontrol_h

/*
 * Button value can be easily foud by looking at the row and column of the button:
 * 3 first bits indicate the row (starting at 0)
 * 2 following bits indicate the column (starting at 0)
 */
#define BUTTON_LIGHT_UP     0b00000
#define BUTTON_LIGHT_DOWN   0b00001
#define BUTTON_OFF          0b00010
#define BUTTON_ON           0b00011
#define BUTTON_RED          0b00100
#define BUTTON_GREEN        0b00101
#define BUTTON_BLUE         0b00110
#define BUTTON_WHITE        0b00111
#define BUTTON_LIGHT_RED    0b01000
#define BUTTON_LIGHT_GREEN  0b01001
#define BUTTON_LIGHT_BLUE   0b01010
#define BUTTON_FLASH        0b01011
#define BUTTON_ORANGE       0b01100
#define BUTTON_CYAN         0b01101
#define BUTTON_PURPLE       0b01110
#define BUTTON_STROBE       0b01111
#define BUTTON_LIGHT_ORANGE 0b10000
#define BUTTON_DARK_CYAN    0b10001
#define BUTTON_LIGHT_PURPLE 0b10010
#define BUTTON_FADE         0b10011
#define BUTTON_YELLOW       0b10100
#define BUTTON_AZURE_BLUE   0b10101
#define BUTTON_PINK         0b10110
#define BUTTON_SMOOTH       0b10111

void initRemoteControl(int sendPin);
void sendSignal(byte button);

#endif