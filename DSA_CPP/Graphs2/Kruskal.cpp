#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{
public:
  int s;
  int d;
  int w;

public:
  Edge() {}
  Edge(int s, int d, int w)
  {
    this->s = s;
    this->d = d;
    this->w = w;
  }
};

bool compare(Edge w1, Edge w2)
{
  return (w1.w < w2.w);
}

void Kruskal(Edge *input, int n, int e)
{
  sort(input, input + e, compare);
  Edge *output = new Edge[n - 1];
  int *parent = new int[n];
  for (int i = 0; i < n; i++)
  {
    parent[i] = i;
  }

  int count = 0;
  int i = 0;
  while (count < n - 1)
  {
    Edge currentEdge = input[i];
    int v1 = currentEdge.s;
    int v2 = currentEdge.d;
    int v1p = parent[v1];
    int v2p = parent[v2];
    while (v1p != parent[v1p])
    {
      v1p = parent[v1p];
    }
    while (v2p != parent[v2p])
    {
      v2p = parent[v2p];
    }

    if (v1p != v2p)
    {
      output[count] = currentEdge;
      count++;
      i++;
      parent[v1p] = v2p;
    }
    else
    {
      i++;
    }
  }
  for (int i = 0; i < n - 1; i++)
  {
    if (output[i].s <= output[i].d)
      cout << output[i].s << " " << output[i].d << " " << output[i].w << endl;
    else
      cout << output[i].d << " " << output[i].s << " " << output[i].w << endl;
  }
}

int main()
{
  int n, e;
  cin >> n >> e;
  Edge *input = new Edge[e];
  for (int i = 0; i < e; i++)
  {
    int s, d, w;
    cin >> s >> d >> w;
    Edge store(s, d, w);
    input[i] = store;
  }

  Kruskal(input, n, e);
  delete[] input;
}