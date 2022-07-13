#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int main()
{
  char ch[1000];
  cout << "Enter characters : " << endl;
  cin.getline(ch, 1000);
  int min = INT_MAX;
  int c = 0;
  int index = 0;
  int len = strlen(ch);
  for (int i = 0; i <= len; i++)
  {
    if (ch[i] != ' ' && i < len)
    {
      c++;
    }
    else
    {
      if (min > c)
      {
        min = c;
        index = i;
        c = 0;
      }
      else
      {
        c = 0;
      }
    }
  }

  for (int i = index - min; i < index; i++)
  {
    cout << ch[i];
  }
  cout << endl;
}