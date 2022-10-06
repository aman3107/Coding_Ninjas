#include <iostream>
#include <string>
using namespace std;

int editDistance3(string s1, string s2)
{
  int m = s1.size();
  int n = s2.size();
  int arr[m + 1][n + 1];
  for (int i = 0; i <= m; i++)
  {
    arr[i][0] = i;
  }
  for (int j = 0; j <= n; j++)
  {
    arr[0][j] = j;
  }

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (s1[m - i] == s2[n - j])
      {
        arr[i][j] = arr[i - 1][j - 1];
      }
      else
      {
        int a = arr[i - 1][j] + 1;
        int b = arr[i][j - 1] + 1;
        int c = arr[i - 1][j - 1] + 1;
        int ans = min(a, min(b, c));
        arr[i][j] = ans;
      }
    }
  }
  return arr[m][n];
}

int editDistanceHelper(string s1, string s2, int **arr)
{
  if (s1.size() == 0 || s2.size() == 0)
    return max(s1.size(), s2.size());
  if (arr[s1.size()][s2.size()] != -1)
    return arr[s1.size()][s2.size()];
  if (s1[0] == s2[0])
    return editDistanceHelper(s1.substr(1), s2.substr(1), arr);
  int x = editDistanceHelper(s1.substr(1), s2, arr) + 1;
  int y = editDistanceHelper(s1, s2.substr(1), arr) + 1;
  int z = editDistanceHelper(s1.substr(1), s2.substr(1), arr) + 1;
  int ans = min(x, min(y, z));
  arr[s1.size()][s2.size()] = ans;
  return arr[s1.size()][s2.size()];
}

int editDistance2(string s1, string s2)
{
  int **arr;
  int m = s1.size();
  int n = s2.size();
  arr = new int *[m + 1];
  for (int i = 0; i <= m; i++)
  {
    arr[i] = new int[n + 1];
    for (int j = 0; j <= n; j++)
    {
      arr[i][j] = -1;
    }
  }
  return editDistanceHelper(s1, s2, arr);
}

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

  cout << editDistance3(s1, s2) << endl;
}