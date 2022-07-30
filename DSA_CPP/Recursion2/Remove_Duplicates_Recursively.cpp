#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

void removeConsecutiveDuplicates(char *str)
{
  if (str[0] == '\0')
    return;
  if (str[0] == str[1])
  {
    int len = strlen(str);
    for (int i = 0; i < len; i++)
      str[i] = str[i + 1];
    str = str - 1;
  }
  removeConsecutiveDuplicates(str + 1);
}

int main()
{
  char ch[1000];
  cout << "Enter string : " << endl;
  cin >> ch;
  removeConsecutiveDuplicates(ch);
  cout << ch << endl;
}