#include <iostream>
using namespace std;
#include "Node.cpp"

void print(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;

  temp = head;
  while (temp != NULL)
  {
    temp->data++;
    temp = temp->next;
  }

  temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  // Statically

  // Node n1(10);
  // Node *head = &n1;
  // Node n2(20);
  // n1.next = &n2;
  // cout << n1.data << " " << n2.data << endl;
  // cout << head->data << endl;

  // // Dynamically

  // Node *n3 = new Node(10);
  // Node *head = n3;
  // Node *n4 = new Node(20);

  // n3->next = n4;

  // Node n1(1);
  // Node *head = &n1;
  // Node n2(2);
  // n1.next = &n2;
  // Node n3(3);
  // n2.next = &n3;
  // Node n4(4);
  // n3.next = &n4;
  // Node n5(5);
  // n4.next = &n5;

  // print(head);
  // print(head);

  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);

  Node *head = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;

  print(head);
  print(head);
}
