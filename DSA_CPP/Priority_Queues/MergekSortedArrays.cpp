#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int> *> input)
{
  // Write your code here
  priority_queue<int, vector<int>, greater<int>> pq;

  vector<int> ans;

  for (int i = 0; i < input.size(); i++)
  {
    for (int j = 0; j < input[i]->size(); j++)
    {
      pq.push(input[i]->at(j));
    }
  }
  while (!pq.empty())
  {
    ans.push_back(pq.top());
    pq.pop();
  }
  return ans;
}

class triplet
{
public:
  int element;
  int arrayIndxex;
  int elemIndex;
};

class compare
{
public:
  bool operator()(triplet t1, triplet t2)
  {
    return (t1.element > t2.element);
  }
};

vector<int> mergeKSortedArraysMin(vector<vector<int> *> input)
{
  vector<int> ans;
  priority_queue<triplet, vector<triplet>, compare> pq;
  for (int i = 0; i < input.size(); i++)
  {
    triplet t;
    t.element = input[i]->at(0);
    t.arrayIndxex = i;
    t.elemIndex = 0;
    pq.push(t);
  }
  while (!pq.empty())
  {
    triplet t = pq.top();
    pq.pop();
    ans.push_back(t.element);
    int arrayIndex = t.arrayIndxex;
    int elemIndex = t.elemIndex;
    if (elemIndex + 1 < input[arrayIndex]->size())
    {
      triplet t;
      t.element = input[arrayIndex]->at(elemIndex + 1);
      t.arrayIndxex = arrayIndex;
      t.elemIndex = elemIndex + 1;
      pq.push(t);
    }
  }
  return ans;
}
int main()
{
  int k;
  cin >> k;

  vector<vector<int> *> input;

  for (int j = 1; j <= k; j++)
  {
    int size;
    cin >> size;
    vector<int> *current = new vector<int>;

    for (int i = 0; i < size; i++)
    {
      int a;
      cin >> a;
      current->push_back(a);
    }

    input.push_back(current);
  }

  vector<int> output = mergeKSortedArraysMin(input);

  for (int i = 0; i < output.size(); i++)
  {
    cout << output[i] << " ";
  }

  return 0;
}