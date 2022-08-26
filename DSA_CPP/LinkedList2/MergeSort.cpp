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

Node *merge(Node *head1, Node *head2)
{
  if (head1 == NULL)
    return head2;
  if (head2 == NULL)
    return head1;

  Node *fh = NULL;
  Node *ft = NULL;

  if (fh == NULL && ft == NULL)
  {
    if (head1->data < head2->data)
    {
      fh = head1;
      ft = head1;
      head1 = head1->next;
    }
    else
    {
      fh = head2;
      ft = head2;
      head2 = head2->next;
    }
  }
  while (head1 != NULL && head2 != NULL)
  {
    if (head1->data < head2->data)
    {
      ft->next = head1;
      ft = head1;
      head1 = head1->next;
    }
    else
    {
      ft->next = head2;
      ft = head2;
      head2 = head2->next;
    }
  }
  while (head1 != NULL)
  {
    ft->next = head1;
    ft = head1;
    head1 = head1->next;
  }
  while (head2 != NULL)
  {
    ft->next = head2;
    ft = head2;
    head2 = head2->next;
  }
  return fh;
}

Node *mergeSort(Node *head)
{
  // Write your code here
  if (head == NULL || head->next == NULL)
  {
    return head;
  }
  Node *slow = head;
  Node *fast = head->next;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  Node *head1 = head;
  Node *head2 = slow->next;
  slow->next = NULL;
  head1 = mergeSort(head1);
  head2 = mergeSort(head2);
  head = merge(head1, head2);
  return head;
}

int main()
{
  Node *head = takeInput();
  head = mergeSort(head);
  print(head);
}