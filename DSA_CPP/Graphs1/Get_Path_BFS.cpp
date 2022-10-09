#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> *getBFS(int **edges, int n, int sv, int ev, bool *visited)
{
  unordered_map<int, int> map;
  visited[sv] = true;
  queue<int> q;
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
        map[i] = front;
        if (i == ev)
        {
          vector<int> *ans = new vector<int>();
          ans->push_back(ev);
          int x = ev;
          while (map[x] != sv)
          {
            ans->push_back(map[x]);
            x = map[x];
          }
          ans->push_back(sv);
          return ans;
        }
      }
    }
  }
  return NULL;
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

  int sv, ev;
  cin >> sv >> ev;

  vector<int> *res = getBFS(edges, n, sv, ev, visited);
  if (res)
  {
    for (int i = 0; i < res->size(); i++)
    {
      cout << res->at(i) << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < n; i++)
  {
    delete[] edges[i];
  }
  delete[] edges;
  delete[] visited;
}