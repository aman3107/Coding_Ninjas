#include <iostream>
#include <cstring>
using namespace std;

void removeX(char ch[])
{
  if (ch[0] == '\0')
    return;
  if (ch[0] == 'x')
  {
    int len = strlen(ch);
    for (int i = 0; i < len; i++)
      ch[i] = ch[i + 1];
    ch = ch - 1;
  }
  removeX(ch + 1);
}

int main()
{
  char input[1000];
  cin.getline(input, 1000);
  removeX(input);
  cout << input << endl;
}