#include <iostream>
using namespace std;

int length(char ch[])
{
  if (ch[0] == '\0')
    return 0;
  return 1 + length(ch + 1);
}

int main()
{
  char ch[1000];
  cin >> ch;
  int len = length(ch);
  cout << len << endl;
}