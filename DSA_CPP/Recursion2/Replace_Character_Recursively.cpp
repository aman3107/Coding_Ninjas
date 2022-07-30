#include <iostream>
#include <cstring>
using namespace std;

void rep_char(char ch[], char c1, char c2)
{
  if (ch[0] == '\0')
    return;
  if (ch[0] == c1)
    ch[0] = c2;
  rep_char(ch + 1, c1, c2);
}

int main()
{
  char ch[100];
  cin >> ch;
  char c1, c2;
  cout << "Enter character 1 and character 2 : " << endl;
  cin >> c1 >> c2;
  rep_char(ch, c1, c2);
  cout << ch << endl;
}