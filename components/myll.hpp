

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

  void Append(char a) {
    Node *n = new Node();
    n->key = a;
    Node *temp = head;
    if (temp) {
      while (temp->next != 0x0) {
        temp = temp->next;
      }
      temp->next = n;
      tail = n;
      return;
    } else {
      head = tail = n;
      return;
    }
  }
    void clear(){
      Node * temp = head;
      Node * t2= 0x0;
      while(temp!=0x0){
        t2 = temp->next;
        delete temp;
        temp=t2;
      }
    }
  Node *peek() { return head; }

  bool isEmpty() { return (head == 0x0); }
};
