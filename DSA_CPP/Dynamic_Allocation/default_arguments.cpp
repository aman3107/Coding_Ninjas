#include <iostream>
using namespace std;

int sum(int arr[], int n, int si = 0)
{
  int ans = 0;
  for (int i = si; i < n; i++)
  {
    ans = ans + arr[i];
  }
  return ans;
}

int main()
{
  int arr[20];

  cout << sum(arr, 20) << endl;
}