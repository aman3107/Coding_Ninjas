#include <iostream>
using namespace std;

void remove(char ch[], char c)
{
  int i = 0;
  int j = 0;
  while (ch[i] != '\0')
  {
    if (ch[i] == c)
    {
      i++;
      continue;
    }
    else
    {
      ch[j] = ch[i];
      i++;
      j++;
    }
  }
  ch[j] = '\0';
}

int main()
{
  char ch[1000];
  cout << "Enter characters : " << endl;
  cin.getline(ch, 1000);
  char c;
  cout << "Enter character : " << endl;
  cin >> c;
  remove(ch, c);
  cout << ch << endl;
}