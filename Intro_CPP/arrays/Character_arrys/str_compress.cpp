#include <iostream>
#include <cstring>
using namespace std;

void str_compress(char ch[])
{
  int i = 0;
  int c = 0;
  int len = strlen(ch);
  string str = "";
  for (int j = 0; j < len; j++)
  {
    if (ch[j] == ch[j + 1])
    {
      c++;
    }

    else if (c == 0)
    {
      str = str + ch[j];
    }

    else
    {
      str = str + ch[j];
      str = str + to_string(c + 1);
      c = 0;
    }
  }
  cout << str << endl;
}

int main()
{
  char ch[1000];
  cout << "Enter characters : " << endl;
  cin.getline(ch, 1000);
  str_compress(ch);
}