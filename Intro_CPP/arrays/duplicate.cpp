#include <iostream>
using namespace std;

int duplicate(int *arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    int count = 0;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] == arr[j])
      {
        count++;
        break;
      }
    }
    if (count == 1)
      return arr[i];
  }
  return -1;
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int ans = duplicate(arr, n);
  cout << "Duplicate element : " << ans << endl;
}