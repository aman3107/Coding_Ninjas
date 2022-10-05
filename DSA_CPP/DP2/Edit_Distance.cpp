#include <iostream>
#include <string>
using namespace std;

int editDistance(string s1, string s2)
{
  if (s1.size() == 0 || s2.size() == 0)
    return max(s1.size(), s2.size());
  if (s1[0] == s2[0])
    return editDistance(s1.substr(1), s2.substr(1));
  int x = editDistance(s1.substr(1), s2) + 1;
  int y = editDistance(s1, s2.substr(1)) + 1;
  int z = editDistance(s1.substr(1), s2.substr(1)) + 1;
  int ans = min(x, min(y, z));
  return ans;
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;

  cout << editDistance(s1, s2) << endl;
}