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

Node *bubbleSort(Node *head)
{
  for (int i = 0; i < length(head) - 1; i++)
  {
    Node *prev = NULL;
    Node *curr = head;
    Node *next = curr->next;

    while (curr->next != NULL)
    {
      if (curr->data > curr->next->data)
      {
        if (prev == NULL)
        {
          curr->next = next->next;
          next->next = curr;
          prev = next;
          head = prev;
        }
        else
        {
          next = curr->next;
          curr->next = next->next;
          prev->next = next;
          next->next = curr;
          prev = next;
        }
      }
      else
      {
        prev = curr;
        curr = curr->next;
      }
    }
  }
  return head;
}

int main()
{
  Node *head = takeInput();
  head = bubbleSort(head);
  print(head);
}