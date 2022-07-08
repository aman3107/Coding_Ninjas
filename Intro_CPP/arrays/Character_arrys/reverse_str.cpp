#include <iostream>
using namespace std;

int main()
{
  char str[100];
  cout << "Enter characters : " << endl;
  cin.getline(str, 100);
  int c = 0;
  while (str[c] != '\0')
  {
    c++;
  }
  int i = 0;
  int j = c - 1;
  while (i < j)
  {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    i++;
    j--;
  }
  cout << str << endl;
}