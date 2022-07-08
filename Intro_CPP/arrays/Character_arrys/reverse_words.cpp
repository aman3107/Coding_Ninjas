#include <iostream>
using namespace std;

void reverse_str(char ch[])
{
  int arr[100];
  arr[0] = -1;
  int c = 0;
  int a = 1;
  while (ch[c] != '\0')
  {
    c++;
  }
  int i = 0;
  int j = c - 1;
  while (i < j)
  {
    char temp = ch[i];
    ch[i] = ch[j];
    ch[j] = temp;
    i++;
    j--;
  }
  for (int i = 0; ch[i] != '\0'; i++)
  {
    if (ch[i] == ' ')
    {
      arr[a] = i;
      a++;
    }
  }
  arr[a] = c;
  for (int i = 0; i < a; i++)
  {
    int r = arr[i] + 1;
    int l = arr[i + 1] - 1;
    while (r < l)
    {
      char temp = ch[r];
      ch[r] = ch[l];
      ch[l] = temp;
      r++;
      l--;
    }
  }

  cout << ch << endl;
}
int main()
{
  char ch[1000];
  cout << "Enter characters : " << endl;
  cin.getline(ch, 1000);
  reverse_str(ch);
}