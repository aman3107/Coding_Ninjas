#include <iostream>
#include <algorithm>
using namespace std;

int Pair_Sum(int *arr, int n, int num)
{
  sort(arr, arr + n);
  int s = 0;
  int e = n - 1;
  int count = 0;
  while (s < e)
  {
    if (arr[s] + arr[e] > num)
      e--;
    else if (arr[s] + arr[e] < num)
      s++;
    else
    {
      int s_ele = arr[s];
      int e_ele = arr[e];
      int s_count = s;
      int e_count = e;
      while (s_count <= e_count && arr[s_count] == s_ele)
        s_count++;
      while (s_count <= e_count && arr[e_count] == e_ele)
        e_count--;
      if (arr[s] == arr[e])
      {
        int cnt = (e - s) + 1;
        count = count + (cnt * (cnt - 1)) / 2;
        return count;
      }

      else
      {
        count = count + ((s_count - s) * (e - e_count));
      }
      s = s_count;
      e = e_count;
    }
  }
  return count;
}

int main()
{
  int n;
  cout << "Enter n " << endl;
  cin >> n;
  int *arr;
  arr = new int[n];

  cout << "Enter elements in the array : " << endl;

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int num;
  cout << "Enter sum number : " << endl;

  cin >> num;

  cout << Pair_Sum(arr, n, num) << endl;

  delete[] arr;
}