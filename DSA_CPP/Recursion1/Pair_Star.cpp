#include <iostream>
#include <cstring>
using namespace std;

void pair_star(char ch[])
{
  if (ch[0] == '\0')
    return;
  if (ch[0] == ch[1])
  {

    int len = strlen(ch);
    for (int i = len + 1; i > 1; i--)
    {
      ch[i] = ch[i - 1];
    }
    ch[1] = '*';
  }
  pair_star(ch + 1);
}

int main()
{
  char input[1000];
  cin.getline(input, 1000);
  pair_star(input);
  cout << input << endl;
}