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

Node *removeDuplicates(Node *head)
{
  if (head == NULL)
  {
    return head;
  }
  Node *temp = head;
  Node *tail = head->next;
  while (tail != NULL)
  {
    if (temp->data == tail->data)
    {
      temp->next = tail->next;
      tail = tail->next;
    }
    else
    {
      temp = temp->next;
      tail = tail->next;
    }
  }
  return head;
}

int main()
{
  Node *head = takeInput();
  head = removeDuplicates(head);
  print(head);
}