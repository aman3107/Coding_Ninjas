#include <iostream>
#include <climits>
using namespace std;

int minDistanceVertex(int *minDistance, bool *visited, int n)
{
  int minDistVer = -1;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i] && (minDistVer == -1 || minDistance[i] < minDistance[minDistVer]))
    {
      minDistVer = i;
    }
  }
  return minDistVer;
}
void Dijkstra(int **edges, int n)
{
  bool *visited = new bool[n];
  int *minDistance = new int[n];
  for (int i = 0; i < n; i++)
  {
    visited[i] = false;
    minDistance[i] = INT_MAX;
  }
  minDistance[0] = 0;
  for (int i = 0; i < n - 1; i++)
  {
    int minDistVer = minDistanceVertex(minDistance, visited, n);
    visited[minDistVer] = true;
    for (int j = 0; j < n; j++)
    {
      if (edges[minDistVer][j] != 0 && !visited[j])
      {
        int dist = edges[minDistVer][j] + minDistance[minDistVer];
        if (dist < minDistance[j])
        {
          minDistance[j] = dist;
        }
      }
    }
  }
  for (int i = 0; i < n - 1; i++)
  {
    cout << i << " " << minDistance[i] << endl;
  }
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
    cin >> s >> d >> w;
    edges[s][d] = w;
    edges[d][s] = w;
  }

  Dijkstra(edges, n);

  for (int i = 0; i < n; i++)
  {
    delete[] edges[i];
  }
  delete[] edges;
}