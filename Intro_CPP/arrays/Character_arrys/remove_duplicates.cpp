#include <iostream>
using namespace std;

void remove_dupli(char ch[])
{
  int j = 0;
  for (int i = 0; ch[i] != '\0'; i++)
  {
    if (ch[i] == ch[i + 1])
      continue;
    else
    {
      ch[j] = ch[i];
      j++;
    }
  }
  ch[j] = '\0';
}

int main()
{
  char ch[1000];
  cout << "Enter characters : " << endl;
  cin >> ch;
  remove_dupli(ch);
  cout << ch << endl;
}