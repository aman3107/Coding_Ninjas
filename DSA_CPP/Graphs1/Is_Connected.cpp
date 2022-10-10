#include <iostream>
#include <queue>
using namespace std;

bool isConnected(int **edges, int n, int sv, bool *visited)
{
  queue<int> q;
  visited[sv] = true;
  q.push(sv);
  while (!q.empty())
  {
    int front = q.front();
    q.pop();
    for (int i = 0; i < n; i++)
    {
      if (i == front)
        continue;
      if (edges[front][i] == 1 && !visited[i])
      {
        visited[i] = true;
        q.push(i);
      }
    }
  }
  bool ans = true;
  for (int i = 0; i < n; i++)
  {
    if (visited[i] == false)
    {
      ans = false;
      break;
    }
  }
  return ans;
}

int main()
{
  int n, e;
  cin >> n >> e;
  int **edges = new int *[n];
  for (int i = 0; i < n; i++)
  {
    edges[i] = new int[n];
    for (int j = 0; j < n; j++)
    {
      edges[i][j] = 0;
    }
  }
  for (int i = 0; i < e; i++)
  {
    int f, s;
    cin >> f >> s;
    edges[f][s] = 1;
    edges[s][f] = 1;
  }

  bool *visited = new bool[n];
  for (int i = 0; i < n; i++)
  {
    visited[i] = false;
  }
  if (isConnected(edges, n, 0, visited))
  {
    cout << "true";
  }
  else
  {
    cout << "false";
  }
}