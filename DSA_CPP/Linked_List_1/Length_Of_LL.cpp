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

int length(Node *head)
{
  int c = 0;
  Node *temp = head;
  while (temp != NULL)
  {
    c++;
    temp = temp->next;
  }
  return c;
}

int main()
{
  Node *n1 = takeInput();
  cout << length(n1) << endl;
}