#include <iostream>
using namespace std;

bool palin(string str, int s, int e)
{
  if (s >= e)
    return true;
  return (str[s] == str[e]) && palin(str, s + 1, e - 1);
}

int main()
{
  string str;
  getline(cin, str);
  int len = str.length();
  bool ans = palin(str, 0, len - 1);
  cout << ans << endl;
}