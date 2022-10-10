#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool DFS(vector<vector<char>> &board, int n, int m, int i, int j, bool **visited, string s)
{
  if (board[i][j] != s[0])
    return false;
  if (s.length() == 1)
    return true;

  visited[i][j] = true;
  bool ans1 = false, ans2 = false, ans3 = false, ans4 = false, ans5 = false, ans6 = false, ans7 = false, ans8 = false;
  if (i - 1 >= 0 && j - 1 >= 0)
  {
    if (!visited[i - 1][j - 1])
      ans1 = DFS(board, n, m, i - 1, j - 1, visited, s.substr(1));
  }
  if (i - 1 >= 0)
  {
    if (!visited[i - 1][j])
      ans2 = DFS(board, n, m, i - 1, j, visited, s.substr(1));
  }
  if (i - 1 >= 0 && j + 1 < m)
  {
    if (!visited[i - 1][j + 1])
      ans3 = DFS(board, n, m, i - 1, j + 1, visited, s.substr(1));
  }

  if (j + 1 < m)
  {
    if (!visited[i][j + 1])
      ans4 = DFS(board, n, m, i, j + 1, visited, s.substr(1));
  }

  if (i + 1 < n && j + 1 < m)
  {
    if (!visited[i + 1][j + 1])
      ans5 = DFS(board, n, m, i + 1, j + 1, visited, s.substr(1));
  }
  if (i + 1 < n)
  {
    if (!visited[i + 1][j])
      ans6 = DFS(board, n, m, i + 1, j, visited, s.substr(1));
  }
  if (i + 1 < n && j - 1 >= 0)
  {
    if (!visited[i + 1][j - 1])
      ans7 = DFS(board, n, m, i + 1, j - 1, visited, s.substr(1));
  }
  if (j - 1 >= 0)
  {
    if (!visited[i][j - 1])
      ans8 = DFS(board, n, m, i, j - 1, visited, s.substr(1));
  }
  if (ans1 or ans2 or ans3 or ans4 or ans5 or ans6 or ans7 or ans8)
  {
    return true;
  }
  else
  {
    visited[i][j] = false;
    return false;
  }
}

bool hasPath(vector<vector<char>> &board, int n, int m)
{
  // Write your code here.
  bool **visited = new bool *[n];
  for (int i = 0; i < n; i++)
  {
    visited[i] = new bool[m];
    for (int j = 0; j < m; j++)
    {
      visited[i][j] = false;
    }
  }
  string s = "CODINGNINJA";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (board[i][j] == 'C')
      {
        bool ans = DFS(board, n, m, i, j, visited, s);
        if (ans)
          return true;
      }
    }
  }
  return false;
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<char>> board(n, vector<char>(m));

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      cin >> board[i][j];
    }
  }

  cout << (hasPath(board, n, m) ? 1 : 0);
}