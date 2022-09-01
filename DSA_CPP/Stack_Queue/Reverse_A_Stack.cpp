#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra)
{
  // while (!input.empty())
  // {
  //   extra.push(input.top());
  //   input.pop();
  // }
  // input.swap(extra);

  if (input.size() <= 1)
    return;

  int x = input.top();
  input.pop();

  reverseStack(input, extra);

  while (!input.empty())
  {
    int temp = input.top();
    input.pop();
    extra.push(temp);
  }

  input.push(x);
  while (!extra.empty())
  {
    int temp = extra.top();
    extra.pop();
    input.push(temp);
  }
}

int main()
{
  stack<int> input, extra;
  int size;
  cin >> size;

  for (int i = 0, val; i < size; i++)
  {
    cin >> val;
    input.push(val);
  }

  reverseStack(input, extra);

  while (!input.empty())
  {
    cout << input.top() << " ";
    input.pop();
  }
}