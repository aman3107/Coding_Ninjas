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
int length(Node *head)
{
  Node *temp = head;
  if (temp == NULL)
    return 0;
  return 1 + length(temp->next);
}

Node *AppendLastNToFirst(Node *head, int n)
{
  int c = 1;
  if (head == NULL)
    return head;
  Node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = head;
  while (c < n)
  {
    temp = temp->next;
    c++;
  }
  Node *a = temp->next;
  head = a;
  temp->next = NULL;
  return head;
}

Node *appendLastNToFirst(Node *head, int n)
{
  int len = length(head);
  int c = 1;
  if (head == NULL)
    return head;
  Node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = head;
  while (c < (len - n) + 1)
  {
    temp = temp->next;
    c++;
  }
  Node *a = temp->next;
  head = a;
  temp->next = NULL;
  return head;
}

int main()
{
  Node *head = takeInput();
  int n;
  cin >> n;
  head = appendLastNToFirst(head, n);
  print(head);
}