#include <iostream>
using namespace std;

int unique(int *arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    int count = 0;
    for (int j = 0; j < n; j++)
    {
      if (j != i)
      {
        if (arr[i] == arr[j])
        {
          count++;
          break;
        }
      }
    }
    if (count == 0)
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
  int ans = unique(arr, n);
  cout << "Unique element : " << ans << endl;
}