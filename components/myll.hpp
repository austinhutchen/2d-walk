

#pragma ONCE

struct Node {
  char key;
  Node *next;
};

class LinkedList {
private:
  Node *head;
  Node *tail;

public:
  LinkedList() { head = tail = 0x0; }
  void Append(Node *n) {
    if (head) {
      tail->next = n;
    } else {
      head = tail = n;
    }
  }


  Node *peek() { return head; }

};
