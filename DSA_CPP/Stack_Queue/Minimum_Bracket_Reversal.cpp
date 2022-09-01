#include <iostream>
#include <string>
#include <stack>
using namespace std;

int countBracketReversals(string input)
{
  stack<int> s;
  int count = 0;
  if (input.length() % 2 == 0)
  {
    for (int i = 0; i < input.length(); i++)
    {
      if (input[i] == '{')
        s.push(input[i]);
      else if (input[i] == '}')
      {
        if (s.empty())
          s.push(input[i]);
        else if (!s.empty() && s.top() == '{')
          s.pop();
        else if (!s.empty() && s.top() == '}')
          s.push(input[i]);
      }
    }
    while (!s.empty())
    {
      char c1 = s.top();
      s.pop();
      char c2 = s.top();
      s.pop();

      if (c1 == c2)
        count++;
      else if (c1 != c2)
        count = count + 2;
    }
  }
  else
  {
    return -1;
  }
  return count;
}

int main()
{
  string input;
  cin >> input;
  cout << countBracketReversals(input);
}
