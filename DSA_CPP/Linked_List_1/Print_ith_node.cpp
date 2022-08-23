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
      tail = tail->next;
    }
    cin >> data;
  }
  return head;
}

void printIthNode(Node *head, int i)
{
  int c = 0;
  Node *temp = head;
  while (c < i && temp != NULL)
  {
    temp = temp->next;
    c++;
  }
  if (temp != NULL)
    cout << temp->data;
  else
    return;
}

int main()
{
  Node *n1 = takeInput();
  int pos;
  cin >> pos;
  printIthNode(n1, pos);
  cout << endl;
}