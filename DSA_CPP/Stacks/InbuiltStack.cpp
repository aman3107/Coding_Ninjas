#include <iostream>
#include <stack>
using namespace std;

int main()
{
  stack<int> s;
  s.push(10);
  s.pop();
  cout << s.empty() << endl;
  s.push(9);
  cout << s.top() << endl;
  cout << s.size() << endl;
}