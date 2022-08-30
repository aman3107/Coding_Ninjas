#include <iostream>
#include "BalancedParanthesis.cpp"
#include <stack>
using namespace std;

bool isBalanced(string str)
{
  // StackUseBalanced<char> s;
  stack<char> s;
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] == '{' or str[i] == '(')
    {
      s.push(str[i]);
    }
    else if (str[i] == '}' or str[i] == ')')
    {
      if (s.empty() == 0)
      {
        if (s.top() == '(' && str[i] == ')')
        {
          s.pop();
        }
        else if (s.top() == '{' && str[i] == '}')
        {
          s.pop();
        }
      }
    }
  }
  if (s.empty())
    return true;
  else
    return false;
}

int main()
{
  string str;
  cout << "Enter String : " << endl;
  cin >> str;

  bool ans = isBalanced(str);

  if (ans)
    cout << "True" << endl;
  else
    cout << "False" << endl;
}