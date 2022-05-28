#define HID_CUSTOM_LAYOUT
#define LAYOUT_NORWEGIAN
#include "HID-Project.h"
#include "Keypad.h"

#define KEY_F25 0xE8

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
  Keyboard.write('f');
}

void b2() {
  Keyboard.write('r');
}

void b3() {
  Keyboard.write(KEY_F15)
}

void b4() {
  Keyboard.write(KEY_F16);
}

void b5() {
  Keyboard.write(KEY_F17);
}

void b6() {
  Keyboard.write(KEY_F18);
}

void b7() {
  Keyboard.write(KEY_F19);
}

void b8() {
  Keyboard.write(KEY_F20);
}

void b9() {
  Keyboard.write(KEY_F21);
}

void b10() {
  Keyboard.write(KEY_F22);
}

void b11() {
  Keyboard.write(KEY_F23);
}

void b12() {
  Keyboard.write(KEY_F24);
}

void b13() {
  Keyboard.write(KEY_F25);
}

void b14() {

}

void b15() {

}

void setup() {
  // put your setup code here, to run once:
  Keyboard.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
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
