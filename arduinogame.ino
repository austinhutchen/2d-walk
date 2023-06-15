
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
struct matrix *m = NULL;

void printList(Node *head) {
  short unsigned count = 0;
  Node *temp = head;
  while (temp != NULL) {
    lcd.print(temp->key);
    count++;
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
  if (p->py == 0) {
    if (counter < 7) {
      // boundary check for map
      counter++;
    } else {
      list->clear();
      counter = 0;
    }
    // moving to right
    for (unsigned short i = list->size(); i < counter; i++) {
      list->Append(' ');
    }

    list->Append('@');
    lcd.setCursor(0, 0);
    printList(list->peek());
  }
  if (p->py >= 800) {
    if (counter > 0) {
      counter--;
      list->pop();
      // need a better function for LL removal
      if (list->size() > 1) {
        list->pop();
      }

    } else {
      // counter ==0;
      lcd.clear();
      lcd.setCursor(0, 0);
      delay(50);
      lcd.print("ERROR");
      lcd.clear();
      delay(50);
      printList(list->peek());
    }
  }
}

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  lcd.begin(16, 2);
}

void loop() {
  while (digitalRead(buttonApin) != LOW) {
    if (list->isEmpty()) {
    list = new LinkedList();
  }
    game(p, list, counter);
    delay(10);
    lcd.clear();
  }

  // EXIT CONDITION
  list->clear();
  delay(10);
  lcd.setCursor(0, 0);
  lcd.print("--->BYE!");
  delay(300);
  lcd.clear();
  free(p);
  return;
}
