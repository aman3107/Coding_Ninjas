#include <iostream>
#include <cstring>
using namespace std;

void replacePi(char ch[])
{
  if (ch[0] == '\0')
    return;
  if (ch[0] == 'p' && ch[1] == 'i')
  {
    ch[0] = '3';
    ch[1] = '.';
    int len = strlen(ch);
    for (int i = len + 2; i > 1; i--)
    {
      ch[i] = ch[i - 2];
    }
    ch[2] = '1';
    ch[3] = '4';
  }
  replacePi(ch + 1);
}

int main()
{
  char ch[1000];
  cin.getline(ch, 1000);
  replacePi(ch);
  cout << ch << endl;
}