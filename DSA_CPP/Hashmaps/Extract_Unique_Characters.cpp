#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string uniqueChar(string str)
{
  // Write your code here
  unordered_map<int, int> map;
  string ans;
  for (int i = 0; i < str.size(); i++)
  {
    if (map.count(str[i]) > 0)
    {
      continue;
    }
    else
    {
      ans = ans + str[i];
      map[str[i]]++;
    }
  }
  return ans;
}

int main()
{
  string str;
  cin >> str;
  cout << uniqueChar(str);
}