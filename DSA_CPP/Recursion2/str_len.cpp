#include <iostream>
#include <cstring>
using namespace std;

void RemoveX(char ch[])
{
  if (ch[0] == '\0')
    return;
  if (ch[0] == 'x')
  {
    int len = strlen(ch);
    for (int i = 0; i < len; i++)
    {
      ch[i] = ch[i + 1];
    }
    ch = ch - 1;
  }
  RemoveX(ch + 1);
}

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
  // int len = length(ch);
  // cout << len << endl;
  RemoveX(ch);
  cout << ch << endl;
}