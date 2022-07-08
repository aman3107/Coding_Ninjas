#include <iostream>
using namespace std;

int main()
{
  char str[100];
  cout << "Enter characters : " << endl;
  cin.getline(str, 100);
  int c = 0;
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (str[i] == ' ')
    {
      continue;
    }
    else
    {
      str[c] = str[i];
      c++;
    }
  }
  str[c] = '\0';
  cout << str << endl;
}