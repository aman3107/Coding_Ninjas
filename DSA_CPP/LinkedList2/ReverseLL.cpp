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

Node *reverseLinkedListRec(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }

  Node *ans = reverseLinkedListRec(head->next);
  head->next->next = head;
  head->next = NULL;

  return ans;
}

int main()
{
  Node *head = takeInput();
  head = reverseLinkedListRec(head);
  print(head);
  delete head;
}