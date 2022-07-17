#include <iostream>
#include <cstring>
using namespace std;

void pair_star(char ch[])
{
  if (strlen(ch) == 1)
    return;
  if (ch[0] == ch[1])
  {
    int len = strlen(ch);
    for (int i = len; i > 1; i--)
    {
      ch[i] = ch[i - 1];
    }
    ch[1] = '*';
    ch[len + 1] = '\0';
    ch = ch + 1;
  }
  pair_star(ch + 1);
}

int main()
{
  char ch[1000];
  cin.getline(ch, 1000);
  pair_star(ch);
  cout << ch;
}