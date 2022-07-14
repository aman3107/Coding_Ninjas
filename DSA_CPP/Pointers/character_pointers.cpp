#include <iostream>
using namespace std;

int main()
{
  char str[] = "abcde";
  char *pstr = "abcde";
  cout << str << endl;
  cout << pstr << endl;

  int a[] = {
      1,
      2,
      3,
  };
  char ch[] = "abc";
  cout << a << endl;
  cout << ch << endl;

  char *c = &ch[0];
  cout << c << endl;

  char c1 = 'a';
  char *pc = &c1;
  cout << c1 << endl;
  cout << pc << endl;
}