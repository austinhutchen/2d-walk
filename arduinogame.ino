
#include "./components/array.hpp"
#include <LiquidCrystal.h>

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int buttonApin = 1;
struct player *p = new player();
matrix *m = new matrix(p, 2, 16);
void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  lcd.begin(16, 2);
}

void display(matrix *matrix) {
  for (int i = 0; i < 2; i++) {
    for (int k = 0; k < 16; k++) {
      lcd.print(matrix->map[i][k]);
    }
  }
}

void game(struct player *p, matrix *grid) {
  if (p->character != '~') {
    p->character = '~';
  }

  if (analogRead(Y_pin) == 0) {

    // moving to right
    m->right();
    display(m);
  }
  if (analogRead(Y_pin) >= 800) {
    // moving left
    m->left();
    display(m);
  }
  if (analogRead(X_pin) == 0) {

    // moving to right
    m->down();
    display(m);
  }
  if (analogRead(X_pin) >= 800) {
    // moving left
    m->up();
    display(m);
  }
}

void loop() {

  while (digitalRead(buttonApin) != LOW) {
    game(p, m);
    delay(100);
    lcd.clear();
  }
  // EXIT CONDITION
  lcd.setCursor(0, 0);
  lcd.print("BYE!");
  delay(300);
  lcd.clear();
  m->clear();
  return;
}
