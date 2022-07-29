#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int str_int(char ch[])
{
  if (strlen(ch) == 1)
    return ch[0] - '0';
  int a = str_int(ch + 1);
  int b = ch[0] - '0';
  int c = b * (int)pow(10, strlen(ch) - 1) + a;
  return c;
}

int main()
{
  char ch[100];
  cin >> ch;
  cout << str_int(ch) << endl;
}