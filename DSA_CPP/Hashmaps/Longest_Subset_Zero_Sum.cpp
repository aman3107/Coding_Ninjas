#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int *arr, int n)
{
  // Write your code here
  int sum = 0;
  int max_len = 0;
  unordered_map<int, int> map;
  for (int i = 0; i < n; i++)
  {
    sum = sum + arr[i];
    if (arr[i] == 0 && max_len == 0)
      max_len = max_len + 1;
    if (sum == 0)
      max_len = i + 1;
    if (map.find(sum) != map.end())
    {
      max_len = max(max_len, i - map[sum]);
    }
    else
    {
      map[sum] = i;
    }
  }
  return max_len;
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

  cout << lengthOfLongestSubsetWithZeroSum(arr, size);

  delete[] arr;
}