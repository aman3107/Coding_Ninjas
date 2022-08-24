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

int findNode(Node *head, int n)
{
  int c = 0;
  while (head != NULL)
  {
    if (head->data == n)
    {
      return c;
    }
    else
    {
      head = head->next;
      c++;
    }
  }
  return -1;
}

int main()
{
  Node *head = takeInput();
  int n;
  cin >> n;
  cout << findNode(head, n) << endl;
}