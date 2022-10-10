#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void BFS(int **edges, int n, int sv, bool *visited, vector<int> *temp)
{
  queue<int> q;
  visited[sv] = true;
  q.push(sv);
  temp->push_back(sv);
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
        temp->push_back(i);
      }
    }
  }
}

void connected_Components(int **edges, int n)
{
  bool *visited = new bool[n];
  for (int i = 0; i < n; i++)
  {
    visited[i] = false;
  }
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      vector<int> *temp = new vector<int>();
      BFS(edges, n, i, visited, temp);
      sort(temp->begin(), temp->end());
      for (int j = 0; j < temp->size(); j++)
      {
        cout << temp->at(j) << " ";
      }
      cout << endl;
    }
  }
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

  connected_Components(edges, n);
  for (int i = 0; i < n; i++)
  {
    delete[] edges[i];
  }
  delete[] edges;
}