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

Node *del(Node *head, int i)
{
  Node *temp = head;
  int c = 1;
  if (head == NULL)
    return head;
  if (i == 0)
  {
    head = head->next;
  }
  else
  {
    while (temp != NULL && c < i)
    {
      temp = temp->next;
      c++;
    }

    if (temp == NULL)
    {
      return head;
    }

    if (temp->next != NULL)
    {
      Node *a = temp->next;
      temp->next = a->next;
      delete a;
    }
  }
  return head;
}

int main()
{
  Node *head = takeInput();
  print(head);
  int index;
  cin >> index;
  head = del(head, index);
  print(head);
}