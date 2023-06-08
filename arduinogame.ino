
#include <LiquidCrystal.h>

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int px = 0;
int py = 0;
void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  lcd.begin(16, 2);
}

void loop() {

  lcd.setCursor(0, 0);
  lcd.print(" X: ");
  px = analogRead(X_pin);
  py = analogRead(Y_pin);
  lcd.print(px);
  lcd.print(" --- ");
  lcd.setCursor(8, 0);
  lcd.print(" Y: ");
  lcd.print(py);
  lcd.setCursor(0, 1);
  // player model will go here‰

  if (px && py) {
    lcd.println('@');
  }

  else {
    lcd.print("       ");
     lcd.println('@');
  }
}
