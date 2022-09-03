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

Node *reverseLinkedList(Node *head)
{
  // Write your code here
  if (head == NULL)
  {
    return head;
  }
  Node *slow = head;
  Node *fast = head->next;
  head->next = NULL;

  while (fast != NULL)
  {
    Node *a = fast->next;
    Node *b = fast;
    fast->next = slow;
    fast = a;
    slow = b;
  }
  return slow;
}
Node *NextLargeNumber(Node *head)
{
  head = reverseLinkedList(head);

  Node *res = head;
  Node *temp, *prev = NULL;

  int carry = 1, sum;

  while (head != NULL)
  {
    sum = carry + head->data;
    carry = (sum >= 10) ? 1 : 0;
    sum = sum % 10;
    head->data = sum;
    temp = head;
    head = head->next;
  }
  if (carry > 0)
    temp->next = new Node(carry);

  return reverseLinkedList(res);
}

int main()
{
  Node *head = takeInput();
  head = NextLargeNumber(head);
  print(head);
}