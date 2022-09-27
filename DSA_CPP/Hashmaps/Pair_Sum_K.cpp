#include <iostream>
#include <unordered_map>
using namespace std;

int pairSum(int *arr, int n, int k)
{
  // Write your code here
  unordered_map<int, int> map;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    if (map.find(arr[i] - k) != map.end())
    {
      ans += map[arr[i] - k];
    }
    else if (map.find(arr[i] + k) != map.end())
    {
      ans += map[arr[i] + k];
    }
    map[arr[i]]++;
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;

  int *arr = new int[n];

  for (int i = 0; i < n; ++i)
  {
    cin >> arr[i];
  }
  int k;
  cin >> k;
  cout << pairSum(arr, n, k);

  delete[] arr;
}