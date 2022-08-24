#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};

Node *takeInput()
{
  int data;
  cin >> data;
  Node *head = NULL;
  Node *tail = NULL;
  while (data != -1)
  {
    Node *newNode = new Node(data);
    if (head == NULL)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
    cin >> data;
  }
  return head;
}

void print(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

Node *del(Node *head, int pos)
{
  if (head == NULL)
    return head;
  if (pos == 0)
  {
    Node *a = head;
    head = a->next;
    delete a;
    return head;
  }
  else
  {
    head->next = del(head->next, pos - 1);
  }
  return head;
}

int main()
{
  Node *head = takeInput();
  cout << "before delete " << endl;
  print(head);
  int index;
  cout << "Enter index " << endl;
  cin >> index;
  cout << "After delete " << endl;
  head = del(head, index);
  print(head);
}