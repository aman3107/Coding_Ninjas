#include <iostream>
#include <climits>
using namespace std;

int minVertex(int *weight, bool *visited, int n)
{
  int minV = -1;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i] && (minV == -1 || weight[i] < weight[minV]))
    {
      minV = i;
    }
  }
  return minV;
}

void prim(int **edges, int n)
{
  bool *visited = new bool[n];
  int *weights = new int[n];
  int *parent = new int[n];
  for (int i = 0; i < n; i++)
  {
    visited[i] = false;
    weights[i] = INT_MAX;
    parent[i] = -1;
  }

  weights[0] = 0;

  for (int i = 0; i < n - 1; i++)
  {
    int minV = minVertex(weights, visited, n);
    visited[minV] = true;
    for (int j = 0; j < n; j++)
    {
      if (edges[minV][j] != 0 && !visited[j])
      {
        if (edges[minV][j] < weights[j])
        {
          weights[j] = edges[minV][j];
          parent[j] = minV;
        }
      }
    }
  }
  for (int i = 1; i < n; i++)
  {
    if (parent[i] < i)
    {
      cout << parent[i] << " " << i << " " << weights[i] << endl;
    }
    else
    {
      cout << i << " " << parent[i] << " " << weights[i] << endl;
    }
  }
  delete[] visited;
  delete[] weights;
  delete[] parent;
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
    int s, d, w;
    cin >> s;
    cin >> d;
    cin >> w;
    edges[s][d] = w;
    edges[d][s] = w;
  }
  prim(edges, n);
  for (int i = 0; i < n; i++)
  {
    delete[] edges[i];
  }
  delete[] edges;
}