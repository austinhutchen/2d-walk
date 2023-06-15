#define NULL 0x0

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
  LinkedList() { head = NULL; }
  // problem is here, in append algorithm
  void Append(char a) {
    Node *n = new Node();
    n->key = a;
    Node *temp = head;
    if (temp) {
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = n;
      return;
    } else {
      head = n;
      return;
    }
  }
  void clear() {
    Node *temp = head;
    Node *t2 = NULL;
    while (temp != NULL) {
      t2 = temp->next;
      delete temp;
      temp = t2;
    }
  }
  Node *peek() { return head; }

  bool isEmpty() { return (head == NULL); }

  unsigned short size() {
    int len = 0;
    Node *temp = head;
    while (temp != NULL) {
      len++;
      temp = temp->next;
    }
    return len;
  }

  Node *last() {
    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    return temp;
  }
  void pop() {
    if(head==NULL){
      return;
    }
    else{
Node *beg = head;
    Node * temp = head->next;
    delete head;
    head=temp;
    delete temp;
    temp=NULL;
    }
 }
};
