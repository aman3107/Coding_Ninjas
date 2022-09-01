#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &input)
{
  if (input.empty())
    return;

  int x = input.front();
  input.pop();
  reverseQueue(input);
  input.push(x);
}

int main()
{
  queue<int> q1;
  int size;
  cin >> size;

  for (int i = 0; i < size; i++)
  {
    int val;
    cin >> val;
    q1.push(val);
  }

  reverseQueue(q1);

  while (!q1.empty())
  {
    cout << q1.front();
    q1.pop();
  }
}