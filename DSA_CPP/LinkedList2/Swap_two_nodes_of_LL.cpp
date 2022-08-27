#include <iostream>
#include <math.h>
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
  delete temp;
}

Node *swapNodes(Node *head, int i, int j)
{
  // Write your code here
  if (j < i)
  {
    i = i + j;
    j = i - j;
    i = i - j;
  }
  Node *temp = head;
  Node *c1 = NULL;
  Node *c2 = NULL;
  Node *prev1 = NULL;
  Node *prev2 = NULL;
  int a = 1;

  if (i == j || head == NULL)
  {
    return head;
  }
  if ((i == 0 || j == 0) && (abs(i - j) == 1))
  {
    cout << "first Case" << endl;
    prev1 = temp;
    c1 = prev1->next;
    prev1->next = c1->next;
    c1->next = prev1;
    head = c1;
  }

  else if (i == 0 || j == 0)
  {
    cout << "Second Case" << endl;
    prev1 = temp;
    c1 = temp->next;
    int a = 1;
    while (a < j && temp->next != NULL)
    {
      temp = temp->next;
      a++;
    }

    if (temp->next != NULL)
    {
      prev2 = temp;
      c2 = temp->next;

      prev2->next = prev1;
      prev1->next = c2->next;
      c2->next = c1;

      head = c2;
    }
    return head;
  }

  else if (abs(i - j) == 1)
  {
    cout << "Third Case" << endl;
    int a = 1;
    while (a < i && temp->next != NULL)
    {
      temp = temp->next;
      a++;
    }

    prev1 = temp;
    c1 = temp->next;
    prev2 = c1->next;
    c2 = prev2->next;

    prev1->next = prev2;
    prev2->next = c1;
    c1->next = c2;
  }

  else
  {
    cout << "Fourth Case" << endl;
    int a = 1;
    while (a < i && temp->next != NULL)
    {
      temp = temp->next;
      a++;
    }
    prev1 = temp;
    c1 = temp->next;

    int b = a;
    while (b < j && temp->next != NULL)
    {
      temp = temp->next;
      b++;
    }
    prev2 = temp;
    c2 = temp->next;

    prev1->next = c2;
    prev2->next = c1;
    Node *c3 = c2->next;
    c2->next = c1->next;
    c1->next = c3;
  }
  return head;
}

int main()
{
  Node *head = takeInput();
  int i, j;
  cin >> i >> j;
  head = swapNodes(head, i, j);
  print(head);
  delete head;
}