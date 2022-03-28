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

byte rowPins[ROWS] = {16,15,14};
byte colPins[COLS] = {4,5,6,7,8};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void b1() {
  Keyboard.write('u');
}

void b2() {
  //Keyboard.write(KEY_F14);
}

void b3() {
  //Keyboard.write(KEY_F15);
}

void b4() {
  //Keyboard.write(KEY_F16);
}

void b5() {
  Keyboard.write('l');
}

void b6() {
  //Keyboard.write(KEY_F18);
}

void b7() {
  //Keyboard.write(KEY_F19);
}

void b8() {
  //Keyboard.write(KEY_F20);
}

void b9() {
  Keyboard.write(KEY_DOWN_ARROW);
  delay(50);
  Keyboard.write(KEY_UP_ARROW);
  delay(50);
  Keyboard.write(KEY_UP_ARROW);
}

void b10() {
  //Keyboard.write(KEY_F22);
}

void b11() {
  //Keyboard.write(KEY_F23);
}

void b12() {
  //Keyboard.write(KEY_DOWN_ARROW);
}

void b13() {
  Keyboard.write(KEY_DOWN_ARROW);
  delay(50);
  Keyboard.write(KEY_LEFT_ARROW);
  delay(50);
  Keyboard.write(KEY_LEFT_ARROW);
}

void b14() {
  Keyboard.write(KEY_DOWN_ARROW);
}

void b15() {
  Keyboard.write(KEY_DOWN_ARROW);
  delay(50);
  Keyboard.write(KEY_RIGHT_ARROW);
  delay(50);
  Keyboard.write(KEY_RIGHT_ARROW);
}

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
};
  
void loop() {
  int pressedKey = customKeypad.waitForKey();
  switch (pressedKey){
    case 1:
      b1();
      break;
    case 2:
      b2();
      break;
    case 3:
      b3();
      break;
    case 4:
      b4();
      break;
    case 5:
      b5();
      break;
    case 6:
      b6();
      break;
    case 7:
      b7();
      break;
    case 8:
      b8();
      break;
    case 9:
      b9();
      break;
    case 10:
      b10();
      break;
    case 11:
      b11();
      break;
    case 12:
      b12();
      break;
    case 13:
      b13();
      break;
    case 14:
      b14();
      break;
    case 15:
      b15();
      break;
  }
}
