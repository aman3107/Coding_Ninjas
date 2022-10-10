#include <iostream>
using namespace std;

void printDFS(int **edges, int n, int sv, bool *visited)
{
  visited[sv] = true;
  for (int i = 0; i < n; i++)
  {
    if (i == sv)
      continue;
    if (edges[sv][i] == 1 && !visited[i])
      printDFS(edges, n, i, visited);
  }
}

int Islands(int **edges, int n)
{
  bool *visited = new bool[n];
  for (int i = 0; i < n; i++)
  {
    visited[i] = false;
  }

  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      count++;
      printDFS(edges, n, i, visited);
    }
  }
  return count;
  delete[] visited;
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

  cout << Islands(edges, n);
  for (int i = 0; i < n; i++)
  {
    delete[] edges[i];
  }
  delete[] edges;
}