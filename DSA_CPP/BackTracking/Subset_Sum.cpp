#include <iostream>
#include <vector>
using namespace std;

int printSubsetSumToK(int input[], int size, int k, int count)
{
  if (size == 0)
  {
    if (k == 0)
      count++;
    return count;
  }

  count = printSubsetSumToK(input + 1, size - 1, k, count);
  count = printSubsetSumToK(input + 1, size - 1, k - input[0], count);
  return count;
}

int main()
{
  int t;

  cin >> t;
  while (t > 0)
  {
    int input[1000], length, k;

    cin >> length;
    cin >> k;
    for (int i = 0; i < length; i++)
      cin >> input[i];
    cout << printSubsetSumToK(input, length, k, 0);
    t--;
  }
}