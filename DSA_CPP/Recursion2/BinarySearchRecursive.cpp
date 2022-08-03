#include <iostream>
using namespace std;

int BinarySearch(int input[], int l, int r, int x)
{
  if (r >= l)
  {
    int mid = l + (r - l) / 2;

    if (input[mid] == x)
      return mid;
    if (input[mid] > x)
    {
      return BinarySearch(input, l, mid - 1, x);
    }
    else
    {
      return BinarySearch(input, mid + 1, r, x);
    }
  }
  return -1;
}

int binarySearch(int input[], int size, int element)
{
  // Write your code here
  return BinarySearch(input, 0, size - 1, element);
}

int main()
{
  int input[100000], length, element, ans;
  cin >> length;
  for (int i = 0; i < length; i++)
  {
    cin >> input[i];
    ;
  }

  cin >> element;
  ans = binarySearch(input, length, element);
  cout << ans << endl;
}