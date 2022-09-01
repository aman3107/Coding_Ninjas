#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool checkRedundantBrackets(string str)
{
  stack<int> s;
  for (int i = 0; i < str.length(); i++)
  {
    int count = 0;
    if (str[i] == ')')
    {
      while (s.top() != '(')
      {
        count++;
        s.pop();
      }
      s.pop();
      if (count < 2)
        return true;
    }
    else
    {
      s.push(str[i]);
    }
  }
  return false;
}

int main()
{
  string input;
  cin >> input;
  cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}