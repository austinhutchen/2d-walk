#include <LiquidCrystal.h>

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int px = 0;
int py = 0;
bool spawned = false;
struct player *p = nullptr;
struct map *m = nullptr;
void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  lcd.begin(16, 2);
}

struct player {
  int px;
  int py;
};

struct map {
  char obj;
};
struct player *allocatep() { return malloc(sizeof(struct player)); }
struct map *allocatem() { return malloc(sizeof(struct map)); }
void game(void *p, void *map) {
  // makes player model

  
}
void clean(struct player *p, struct map *m) {
  if (p && m) {
    delete p;
    delete m;
  }
  return;
}
void loop() {

  if (spawned == false) {
    struct player *p = allocatep();
    struct map *m = allocatem();
    spawned = true;
  } else {
    while (spawned) {
      lcd.setCursor(0, 0);
      lcd.print(" X: ");
      px = analogRead(X_pin);
      py = analogRead(Y_pin);
      p->px = px;
      p->py = py;
      lcd.print(p->px);
      lcd.print(" --- ");
      lcd.setCursor(8, 0);
      lcd.print(" Y: ");
      lcd.print(p->py);
      lcd.setCursor(0, 1);
      // player model will go here‰
      // game(p,m);
      if (px && py) {
        lcd.print('@');
      } else {
        lcd.print("       ");
        lcd.print('@');
      }
    }
  }

  clean(p, m);
  return;
}
