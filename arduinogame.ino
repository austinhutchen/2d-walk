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


void move(struct player *p){
  p->px = analogRead(X_pin);
  p->py = analogRead(Y_pin);
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
    struct player *p = malloc(sizeof(struct player));
    struct map *m = malloc(sizeof(struct map));
    spawned = true;
  } else {
    while (spawned) {
      lcd.setCursor(0, 0);
      lcd.print(" X: ");
      move(p);
      lcd.print(p->px);
      lcd.print(" --- ");
      lcd.setCursor(8, 0);
      lcd.print(" Y: ");
      lcd.print(p->py);
      lcd.setCursor(0, 1);
      // player model will go here‰
      // game(p,m);
      if (p->px && p->py) {
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
