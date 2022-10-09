#include <iostream>
#include <vector>
using namespace std;

vector<int> getPath(int **edges, int n, int sv, int ev, bool *visited)
{
  if (sv == ev)
  {
    vector<int> output;
    visited[sv] = true;
    output.push_back(sv);
    return output;
  }

  visited[sv] = true;
  vector<int> output;
  for (int i = 0; i < n; i++)
  {
    if (i == sv)
      continue;
    if (edges[sv][i] == 1 && !visited[i])
    {
      output = getPath(edges, n, i, ev, visited);
      if (!output.empty())
      {
        output.push_back(sv);
        return output;
      }
    }
  }
  return output;
}

int main()
{
  int n;
  int e;
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

  int sv, ev;
  cin >> sv >> ev;

  vector<int> output = getPath(edges, n, sv, ev, visited);
  cout << output.size() << endl;
  for (int i = 0; i < output.size(); i++)
  {
    cout << output[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < n; i++)
  {
    delete[] edges[i];
  }
  delete[] edges;
  delete[] visited;
}