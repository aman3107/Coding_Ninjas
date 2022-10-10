#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool dfs(unordered_map<int, vector<int>> &graph, vector<bool> &visited, int start, int length = 1, int parent = -1)
{
  visited[start] = true;
  bool flag = false;
  for (auto currentChild : graph[start])
  {
    if (!visited[currentChild])
    {
      flag = dfs(graph, visited, currentChild, length + 1, start);
      if (flag)
      {
        break;
      }
    }
    else
    {

      if (parent != currentChild and length > 3)
      {
        return true;
      }
    }
  }

  return flag;
}

bool hasCycle(vector<vector<char>> &board, int n, int m)
{
  // Write your code here.
  unordered_map<int, vector<int>> graph;
  vector<vector<int>> value(n, vector<int>(m, -1));

  int count = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      value[i][j] = count++;
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {

      if (j - 1 >= 0 and board[i][j] == board[i][j - 1])
      {
        graph[value[i][j]].push_back(value[i][j - 1]);
      }

      if (j + 1 < m and board[i][j] == board[i][j + 1])
      {
        graph[value[i][j]].push_back(value[i][j + 1]);
      }

      if (i - 1 >= 0 and board[i][j] == board[i - 1][j])
      {
        graph[value[i][j]].push_back(value[i - 1][j]);
      }

      if (i + 1 < n and board[i][j] == board[i + 1][j])
      {
        graph[value[i][j]].push_back(value[i + 1][j]);
      }
    }
  }

  vector<bool> visited(count, false);

  for (int i = 0; i < count; i++)
  {
    if (!visited[i])
    {
      bool cycle = dfs(graph, visited, i);
      if (cycle)
      {
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

  cout << (hasCycle(board, n, m) ? "true" : "false");
}