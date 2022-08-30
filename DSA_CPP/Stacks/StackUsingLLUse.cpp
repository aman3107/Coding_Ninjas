#include <iostream>
#include "StackUsingLL.cpp"
using namespace std;

int main()
{
  StackUsingLL<char> s1;
  s1.push(100);
  s1.push(101);
  s1.push(102);
  s1.push(103);
  s1.push(104);
  s1.push('A');
  cout << s1.getSize() << endl;
  cout << s1.isEmpty() << endl;
  cout << s1.pop() << endl;
  cout << s1.top() << endl;
}