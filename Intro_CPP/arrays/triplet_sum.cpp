#include <iostream>
using namespace std;

int triplet_sum(int *arr, int n, int x)
{
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      for (int k = j + 1; k < n; k++)
      {
        if (arr[i] + arr[j] + arr[k] == x)
          count++;
      }
    }
  }
  return count;
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int x;
  cout << "Enter number to sum : " << endl;
  cin >> x;
  int arr[n];
  cout << "Enter elements in the array : " << endl;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int ans = triplet_sum(arr, n, x);
  cout << "Total triplet sum : " << ans << endl;
}