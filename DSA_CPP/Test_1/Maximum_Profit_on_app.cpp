#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int maximumProfit(int budget[], int n)
{
  int ans = INT_MIN;
  int price = 0;
  sort(budget, budget + n);
  for (int i = 0; i < n; i++)
  {
    int count = (n - i);
    if (ans < count * budget[i])
    {
      price = budget[i];
      ans = count * budget[i];
    }
  }
  return ans;
}

int main()
{
  int n, *input, i, *cost;
  cin >> n;
  input = new int[n];
  for (i = 0; i < n; i++)
    cin >> input[i];

  cout << maximumProfit(input, n) << endl;
}