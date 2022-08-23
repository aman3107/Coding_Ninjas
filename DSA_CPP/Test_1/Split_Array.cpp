#include <iostream>
using namespace std;

bool helper(int *arr, int n, int s, int lsum, int rsum)
{
  if (s == n)
    return lsum == rsum;

  if (arr[s] % 5 == 0)
    lsum += arr[s];
  else if (arr[s] % 3 == 0)
  {
    rsum += arr[s];
  }
  else
  {
    return helper(arr, n, s + 1, lsum + arr[s], rsum) || helper(arr, n, s + 1, lsum, rsum + arr[s]);
  }
  return helper(arr, n, s + 1, lsum, rsum);
}

bool splitArray(int *input, int size)
{
  return helper(input, size, 0, 0, 0);
}

int main()
{
  int size;
  cin >> size;
  int *input = new int[1 + size];

  for (int i = 0; i < size; i++)
    cin >> input[i];

  if (splitArray(input, size))
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }

  return 0;
}