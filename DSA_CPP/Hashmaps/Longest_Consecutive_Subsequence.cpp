#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
  // Your Code goes here
  unordered_map<int, bool> map;
  unordered_map<int, int> index;
  for (int i = 0; i < n; i++)
  {
    map[arr[i]] = true;
    if (index.count(arr[i]) == 0)
      index[arr[i]] = i;
  }
  int max_len = 1;
  int start = 0;

  for (int i = 0; i < n; i++)
  {
    if (map[arr[i]] == false)
      continue;

    int nsize = 0, nstart = arr[i];
    int j = arr[i];

    while (map.count(j) > 0 && map[j] == true)
    {
      nsize += 1;
      map[j] = false;
      j++;
    }
    j = arr[i] - 1;

    while (map.count(j) > 0 && map[j] == true)
    {
      nstart = j;
      nsize += 1;
      map[j] = false;
      j--;
    }
    if (nsize >= max_len)
    {
      if (max_len == nsize)
      {
        if (index[start] > index[nstart])
          start = nstart;
      }
      else
        start = nstart;

      max_len = nsize;
    }
  }

  vector<int> v;
  v.push_back(start);
  v.push_back(start + (max_len - 1));
  return v;
}

int main()
{
  int size;
  cin >> size;

  int *arr = new int[size];

  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }

  vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

  for (auto i = ans.begin(); i != ans.end(); ++i)
    cout << *i << " ";

  delete[] arr;
}