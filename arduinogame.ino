
#include "./components/myll.hpp"
#include <LiquidCrystal.h>
struct player {
  // track current player position on map
  int px;
  int py;
};
struct matrix {
  // track previous player position on map
  int x;
  int y;
};
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int buttonApin = 1;
short unsigned counter = 0;
LinkedList *list = new LinkedList();
struct player *p = malloc(sizeof(struct player));
struct matrix *m = 0x0;

void printList(Node *head) {
  lcd.setCursor(0, 0);
  short unsigned count = 0;
  Node *temp = head;
  while (temp != 0x0) {
    lcd.print(temp->key);
    count++;
    lcd.setCursor(0, count);
    temp = temp->next;
  }
}

void move(struct player *p) {
  p->px = analogRead(X_pin);
  p->py = analogRead(Y_pin);
  return;
}

void game(struct player *p, LinkedList *list, unsigned short counter) {
  // algorithm for running the game itself
  lcd.setCursor(0, 1);
  move(p);
  lcd.print(" X: ");
  lcd.print(p->px);
  lcd.setCursor(8, 1);
  lcd.print(" Y: ");
  lcd.print(p->py);
  // player model will go here‰
  // game(p,m);
  if (p->px <= 300) {
    // moving to right
    for (unsigned short i = list->size(); i < counter; i++) {
      list->Append(' ');
    }
    if (counter < 7) {
      // boundary check for map
      counter++;
    } else {
      counter--;
    }
    list->Append('@');
    printList(list->peek());
  }
}

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  lcd.begin(16, 2);
}

void loop() {
  while (digitalRead(buttonApin) != LOW) {
    game(p, list, counter);
    delay(100);
    lcd.clear();
  }

  // EXIT CONDITION
  list->clear();
  lcd.setCursor(0, 0);
  lcd.clear();
  delay(10);
  lcd.print("--->BYE!");
  delay(500);
  lcd.clear();
  free(p);
  p = 0x0;
  return;
}
