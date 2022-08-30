#include <iostream>
#include "StackUsingLL.cpp"
using namespace std;

int main()
{
  StackUsingLL s1;
  s1.push(13);
  s1.push(47);
  cout << s1.getSize() << endl;
  cout << s1.isEmpty() << endl;
  cout << s1.pop() << endl;
  cout << s1.top() << endl;
}