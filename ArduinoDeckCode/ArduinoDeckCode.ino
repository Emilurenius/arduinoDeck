#define KEY_RIGHT_SHIFT 0x85
#define KEY_RIGHT_ALT   0x86
#define KEY_RIGHT_GUI   0x87
#define KEY_UP_ARROW    0xDA
#define KEY_DOWN_ARROW  0xD9
#define KEY_LEFT_ARROW  0xD8
#define KEY_RIGHT_ARROW 0xD7
#define KEY_BACKSPACE   0xB2
#define KEY_TAB         0xB3
#define KEY_RETURN      0xB0
#define KEY_ESC         0xB1
#define KEY_INSERT      0xD1
#define KEY_DELETE      0xD4
#define KEY_PAGE_UP     0xD3
#define KEY_PAGE_DOWN   0xD6
#define KEY_HOME        0xD2
#define KEY_END         0xD5
#define KEY_CAPS_LOCK   0xC1
#define KEY_F1          0xC2
#define KEY_F2          0xC3
#define KEY_F3          0xC4
#define KEY_F4          0xC5
#define KEY_F5          0xC6
#define KEY_F6          0xC7
#define KEY_F7          0xC8
#define KEY_F8          0xC9
#define KEY_F9          0xCA
#define KEY_F10         0xCB
#define KEY_F11         0xCC
#define KEY_F12         0xCD
#define KEY_F13         0x8D
#define KEY_F14         0x8C
#define KEY_F15         0x8D
#define KEY_F16         0x8E
#define KEY_F17         0x8F
#define KEY_F18         0x9C
#define KEY_F19         0x9D
#define KEY_F20         0x9E
#define KEY_F21         0x9F
#define KEY_F22         0xD8
#define KEY_F23         0xD9
#define KEY_F24         0xDA
#define KEY_F25         0xE8
#define KEY_LEFT_CTRL   0x98
#define KEY_NUM_period  0xEB

#include <Keypad.h>
#include <Keyboard.h>
#define ROWS 3
#define COLS 5

char hexaKeys[ROWS][COLS] = {
  {0x01, 0x02, 0x03, 0x04, 0x05},
  {0x06, 0x07, 0x08, 0x09, 0x0A},
  {0x0B, 0x0C, 0x0D, 0x0E, 0x0F}
};

char keys[15][64] = {
  {KEY_F13},
  {KEY_F14},
  {KEY_F15},
  {KEY_F16},
  {KEY_F17},
  {KEY_F18},
  {KEY_F19},
  {KEY_F20},
  {KEY_F21},
  {KEY_F22},
  {KEY_F23},
  {KEY_F24},
  {KEY_F25},
  {KEY_DELETE},
  {KEY_CAPS_LOCK},
  }; // Characters
//char Delay[15][255] // delay
//unsigned long delays[5] = {150, 25000, 10, 1, 500}

byte rowPins[ROWS] = {16,15,14};
byte colPins[COLS] = {4,5,6,7,8};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void standardMode() {
  int pressedKey = customKeypad.getKey();
  if (pressedKey != 0) {
    Serial.print(pressedKey);
    for (byte i = 0; i < sizeof(keys[pressedKey-1]) / sizeof(keys[pressedKey-1][0]); i++) {
      Keyboard.write(keys[pressedKey-1][i]);
    }
  }
}

void programMode() {
  int i = 0;
  int selectedKey = Serial.read();

  memset(keys[selectedKey-1], 0, sizeof keys[selectedKey-1]);
  
  while (Serial.available()) {
    int data = Serial.read();
    Serial.print(data);
    keys[selectedKey-1][i] = data;
    i++;
  }
}

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
};
  
void loop() {
  if (Serial.available()) {
    Serial.println("Program mode activated");
    programMode();
  }
  else {
    standardMode();
  }
}
