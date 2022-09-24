#include <iostream>
#include <unordered_map>
using namespace std;

int highestFrequency(int arr[], int n)
{
  // Write your code here
  unordered_map<int, int> max_freq;
  int pos = -1;
  int maxFreq = 0;
  for (int i = 0; i < n; i++)
  {
    max_freq[arr[i]]++;
    if (maxFreq <= max_freq[arr[i]])
    {
      pos = i;
      maxFreq = max_freq[arr[i]];
    }
  }
  return arr[pos];
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

  cout << highestFrequency(arr, n) << endl;

  delete[] arr;
}