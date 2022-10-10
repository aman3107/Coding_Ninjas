#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>> &cake, int n, int i, int j, bool **visited, int &s)
{
  visited[i][j] = true;
  if (cake[i][j] == 1)
    s++;
  if (cake[i][j] != 1)
    return;
  if (i - 1 >= 0)
  {
    if (!visited[i - 1][j])
      DFS(cake, n, i - 1, j, visited, s);
  }
  if (j + 1 < n)
  {
    if (!visited[i][j + 1])
      DFS(cake, n, i, j + 1, visited, s);
  }
  if (i + 1 < n)
  {
    if (!visited[i + 1][j])
      DFS(cake, n, i + 1, j, visited, s);
  }
  if (j - 1 >= 0)
  {
    if (!visited[i][j - 1])
      DFS(cake, n, i, j - 1, visited, s);
  }
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
  // Write your code here
  bool **visited = new bool *[n];
  for (int i = 0; i < n; i++)
  {
    visited[i] = new bool[n];
    for (int j = 0; j < n; j++)
    {
      visited[i][j] = false;
    }
  }
  int lar = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (cake[i][j] == 1 && !visited[i][j])
      {
        int s = 0;
        DFS(cake, n, i, j, visited, s);
        lar = max(lar, s);
      }
    }
  }
  return lar;
}

int main()
{
  int n;
  cin >> n;

  vector<vector<int>> cake(n, vector<int>(n));

  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cin >> cake[i][j];
    }
  }

  cout << getBiggestPieceSize(cake, n);
}