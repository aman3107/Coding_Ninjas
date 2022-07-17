#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

int str_int(char ch[])
{
  if (strlen(ch) == 1)
    return ch[0] - '0';
  int a = str_int(ch + 1);
  int b = ch[0] - '0';
  b = b * (int)pow(10, strlen(ch) - 1) + a;
  return b;
}

int main()
{
  char ch[1000];
  cin.getline(ch, 1000);
  int ans = str_int(ch);
  cout << ans << endl;
}