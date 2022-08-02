#include <iostream>
using namespace std;

int main()
{
  string s = "abc";
  cout << s << endl;
  string s1;
  getline(cin, s1);
  cout << s1 << endl;

  string s2 = s + s1;
  cout << s2 << endl;

  s += s1;

  cout << s.size() << endl;
  cout << s.length() << endl;
  cout << s.substr(1, 3);
  cout << s.find("def");
}