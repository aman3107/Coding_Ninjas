#include <iostream>
#include <string>
using namespace std;

int LCS3(string s1, string s2)
{
  int m = s1.size();
  int n = s2.size();
  int arr[m + 1][n + 1];
  for (int i = 0; i <= m; i++)
  {
    arr[i][0] = 0;
  }
  for (int i = 0; i <= n; i++)
  {
    arr[0][i] = 0;
  }
  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (s1[m - i] == s2[n - j])
      {
        arr[i][j] = 1 + arr[i - 1][j - 1];
      }
      else
      {
        int a = arr[i - 1][j];
        int b = arr[i][j - 1];
        int c = arr[i - 1][j - 1];
        int ans = max(a, max(b, c));
        arr[i][j] = ans;
      }
    }
  }
  return arr[m][n];
}

int LCS2Helper(string s1, string s2, int **arr)
{
  if (s1.size() == 0 || s2.size() == 0)
    return 0;
  if (arr[s1.size()][s2.size()] != -1)
    return arr[s1.size()][s2.size()];

  if (s1[0] == s2[0])
    return 1 + LCS2Helper(s1.substr(1), s2.substr(1), arr);

  int a = LCS2Helper(s1.substr(1), s2, arr);
  int b = LCS2Helper(s1, s2.substr(1), arr);
  int c = LCS2Helper(s1.substr(1), s2.substr(1), arr);
  int ans = max(a, max(b, c));
  arr[s1.size()][s2.size()] = ans;
  return arr[s1.size()][s2.size()];
}

int LCS2(string s1, string s2)
{
  int m = s1.size();
  int n = s2.size();
  int **arr;
  arr = new int *[m + 1];
  for (int i = 0; i <= m; i++)
  {
    arr[i] = new int[n + 1];
    for (int j = 0; j <= n; j++)
    {
      arr[i][j] = -1;
    }
  }
  return LCS2Helper(s1, s2, arr);
}

int LCS(string s1, string s2)
{
  if (s1.size() == 0 || s2.size() == 0)
    return 0;
  if (s1[0] == s2[0])
    return 1 + LCS(s1.substr(1), s2.substr(1));

  int a = LCS(s1.substr(1), s2);
  int b = LCS(s1, s2.substr(1));
  int c = LCS(s1.substr(1), s2.substr(1));
  int ans = max(a, max(b, c));
  return ans;
}

int main()
{
  string s1, s2;
  cin >> s1 >> s2;

  cout << LCS3(s1, s2) << endl;
}