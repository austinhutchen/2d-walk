#include "./components/LinkedList.hpp"
#include <LiquidCrystal.h>
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
//                BS  E  D4 D5  D6 D7
int counter=0;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
bool spawned = false;
struct player *p = nullptr;
struct map *m = nullptr;

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("-- WELCOME! --");
}

struct player {
  int px;
  int py;
};

struct map {
  char obj;
};

void move(struct player *p) {
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
  LinkedList<char> list;
  int counter = 0;
  if (spawned == false) {
    p = malloc(sizeof(struct player));
    m = malloc(sizeof(struct map));
    spawned = true;
  } else {
    while (spawned) {
      lcd.setCursor(0, 0);
      move(p);
      lcd.print(" X: ");
      lcd.print(p->px);
      lcd.print(" --- ");
      lcd.setCursor(8, 0);
      lcd.print(" Y: ");
      lcd.print(p->py);
      lcd.setCursor(0, 1);
      // player model will go here‰
      // game(p,m);
      if (p->px ==0 && p->py == 0) {
        // moving to right
        // uses linked list
        counter++;
        for(int i=0;i<counter;i++){
                list.Append(' ');
        }
        list.Append('@');
        char character;
        if (list.moveToStart()) {
          do {
            character = list.getCurrent();
            lcd.print(character);
          } while (list.next());
        }
      } else if (p->px == 500 && p->py == 500) {
        // joystick still
        lcd.print("        @");
      }
    }
  }

  delay(100);
  lcd.clear();
  counter = 0;
  clean(p, m);
  return;
}
