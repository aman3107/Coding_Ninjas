#include <iostream>
#include <unordered_map>
using namespace std;

int pairSum(int *arr, int n)
{
  // Write your code here
  unordered_map<int, int> map;
  int ans = 0;
  int k = 0;
  for (int i = 0; i < n; i++)
  {
    if (map.find(k - arr[i]) != map.end())
    {
      ans += map[k - arr[i]];
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

  cout << pairSum(arr, n);

  delete[] arr;
}