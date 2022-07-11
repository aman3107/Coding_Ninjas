#include <iostream>
#include <cstring>
using namespace std;

void reverse_word(char ch[])
{
  int c = 0;
  int arr[100];
  arr[0] = -1;
  int i = 1;
  int len = strlen(ch);
  for (int j = 0; j <= len; j++)
  {
    if (ch[c] == ' ' || ch[c] == '\0')
    {
      arr[i] = c;
      int r = arr[i - 1] + 1;
      int l = c - 1;
      while (r < l)
      {
        char temp = ch[r];
        ch[r] = ch[l];
        ch[l] = temp;
        r++;
        l--;
      }
      i++;
      c++;
    }
    c++;
  }
}

int main()
{
  char ch[1000];
  cout << "Enter characters : " << endl;
  cin.getline(ch, 1000);
  reverse_word(ch);
  cout << ch << endl;
}