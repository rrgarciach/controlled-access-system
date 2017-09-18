#include "Keypad.h"

const byte Rows = 4;
const byte Cols = 3;

char keymap[Rows][Cols] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rPins[Rows] = {A6, A5, A4, A3};
byte cPins[Cols] = {A2, A1, A0};

Keypad kpd = Keypad(makeKeypad(keymap), rPins, cPins, Rows, Cols);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char keypressed = kpd.getKey();
  if (keypressed != NO_KEY) {
    Serial.println(keypressed);
  }
}
