#include <iostream>
#include "StatckUsingTemplates.cpp"
using namespace std;

int main()
{
  StackUsingTemp<int> s1;
  s1.push(10);
  s1.push(20);
  s1.push(30);
  s1.push(40);
  s1.push(50);
  s1.push(60);

  cout << s1.top() << endl;
  cout << s1.pop() << endl;
  cout << s1.top() << endl;
  s1.push(70);
  cout << s1.top() << endl;
  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
  cout << s1.pop() << endl;
}