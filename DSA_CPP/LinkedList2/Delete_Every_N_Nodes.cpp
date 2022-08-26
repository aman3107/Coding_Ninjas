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

Node *skipMdeleteN(Node *head, int m, int n)
{
  // Write your code here
  if (m == 0)
  {
    return NULL;
  }
  Node *temp = head;
  Node *tail = head;
  while (tail != NULL)
  {
    int i = 1;
    while (i < m && tail->next != NULL)
    {
      tail = tail->next;
      i++;
    }
    temp = tail;
    int j = 0;
    while (j < n && tail->next != NULL)
    {
      tail = tail->next;
      j++;
    }
    temp->next = tail->next;
    temp = tail->next;
    tail = tail->next;
  }
  delete tail;
  delete temp;
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

int main()
{
  Node *head = takeInput();
  int m, n;
  cin >> m >> n;
  head = skipMdeleteN(head, m, n);
  print(head);
  delete head;
}