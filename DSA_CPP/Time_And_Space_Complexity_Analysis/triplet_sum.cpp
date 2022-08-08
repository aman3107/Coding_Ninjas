#include <iostream>
#include <algorithm>
using namespace std;

int triplet_sum(int *arr, int n, int num)
{
  sort(arr, arr + n);
  int count = 0;
  for (int i = 0; i < n - 2; i++)
  {
    int target = num - arr[i];
    int l = i + 1;
    int r = n - 1;
    while (l < r)
    {
      int x = arr[l];
      int y = arr[r];
      int sum = x + y;
      if (sum < target)
      {
        l++;
      }
      else if (sum > target)
      {
        r--;
      }
      else
      {
        if (x == y)
        {
          count = count + ((r - l) * (r - l + 1)) / 2;
          l = r;
        }
        else
        {
          int c1 = 1;
          int c2 = 1;
          while (l < r && arr[l] == arr[l + 1])
          {
            c1++;
            l++;
          }
          while (l <= r && arr[r] == arr[r - 1])
          {
            c2++;
            r--;
          }
          count = count + (c2 * c1);
          l++;
          r--;
        }
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
  int *arr;
  arr = new int[n];

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int num;
  cout << "Enter sum number : " << endl;
  cin >> num;

  int ans = triplet_sum(arr, n, num);
  cout << ans;
  cout << endl;

  delete[] arr;
}