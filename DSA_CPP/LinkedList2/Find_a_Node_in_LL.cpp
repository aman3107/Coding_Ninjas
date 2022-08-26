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

int findNodeRec(Node *head, int n)
{
  // Write your code here
  if (head == NULL)
  {
    return -1;
  }
  if (head->data == n)
    return 0;

  int index = findNodeRec(head->next, n);
  if (index != -1)
    return 1 + index;
  else
    return -1;
}

int main()
{
  Node *head = takeInput();
  int n;
  cin >> n;
  cout << findNodeRec(head, n) << endl;
}