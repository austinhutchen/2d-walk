//www.elegoo.com
//2016.12.09
#include <LiquidCrystal.h>
// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
    lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print(analogRead(X_pin));
  lcd.setCursor(0, 1);
  lcd.print(analogRead(Y_pin));
  delay(500);
}
