#include "Keypad.h"

// board's pinout:
int lockRelPin = 2;
int buzzerPin = 3;

char keysPressed[4];

const byte Rows = 4;
const byte Cols = 3;

char keymap[Rows][Cols] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

// Assign digital pinouts for keypad 1:
byte rPins1[Rows] = {40, 42, 44, 46};
byte cPins1[Cols] = {48, 50, 52};

// Assign digital pinouts for keypad 2:
byte rPins2[Rows] = {41, 43, 45, 47};
byte cPins3[Cols] = {49, 51, 53};

Keypad kpd1 = Keypad(makeKeypad(keymap), rPins, cPins, Rows, Cols);
Keypad kpd2 = Keypad(makeKeypad(keymap), rPins, cPins, Rows, Cols);

void setup() {
  Serial.begin(9600);
  pinMode(lockRelPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  char key = kpd.getKey();
  if (key != NO_KEY) {
    Serial.println(key);
    onKeyPressed(key);
  }
}

void onKeyPressed(char key) {
  const index = sizeof(keysPressed);
  keysPressed
}

void openLock() {
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(lockRelPin, HIGH);
  delay(3000);
  digitalWrite(lockRelPin, LOW);
  digitalWrite(buzzerPin, LOW);
}

void buzzForFail() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(lockRelPin, HIGH);
    delay(100);
    digitalWrite(lockRelPin, LOW);
    delay(100);
  }
}
