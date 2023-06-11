
#include "./components/myll.hpp"
#include <LiquidCrystal.h>
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
bool spawned = false;
struct player *p = nullptr;
struct map *m = nullptr;

struct player {
  int px;
  int py;
};
struct map{
  int x;
  int y;
}
void printList(Node *head) {
  short unsigned count = 0;
  Node *temp = head;
  while (temp) {
    lcd.print(temp->key);
    count++;
    lcd.setCursor(0, count);
    temp = temp->next;
  }
}

void move(struct player *p) {
  if (analogRead(X_pin) && analogRead(Y_pin)) {
    p->px = analogRead(X_pin);
    p->py = analogRead(Y_pin);
  } else {
    printf("%d", " READ ERROR \n");
  }
}

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  lcd.begin(16, 2);
}

void loop() {
  // add exit button to circuit board
  // use map struct to determine previous position vs current position 
  // 
  LinkedList list = LinkedList();
  short unsigned counter = 0;
  if (spawned == false) {
    p = malloc(sizeof(struct player));
    map = malloc(sizeof(struct map));
    spawned = true;
  } else {
    lcd.setCursor(0, 1);
    move(p);
    lcd.print(" X: ");
    lcd.print(p->px);
    lcd.setCursor(8, 1);
    lcd.print(" Y: ");
    lcd.print(p->py);
    lcd.setCursor(0, 0);
    // player model will go here‰
    // game(p,m);
    if (p->px <= 300) {
      // moving to right
      for (unsigned short i = 0; i < counter; i++) {
        list.Append(' ');
      }
      counter++;
      list.Append('@');
      printList(list.peek());
    }
    if (counter>3) {
      // this condition will need changing to execute movement
      counter = 0;
      free(p);
      list.clear();
      p = 0x0;
      return;
    }
  }
  delay(10);
  lcd.clear();
}
