#include <iostream>
using namespace std;

void subset(string &str, int s, int e, string curr)
{
  if (s == e)
  {
    cout << curr << " ";
    return;
  }
  subset(str, s + 1, e, curr);
  subset(str, s + 1, e, curr + str[s]);
}

int main()
{
  string str;
  getline(cin, str);
  int len = str.length();
  subset(str, 0, len, " ");
}