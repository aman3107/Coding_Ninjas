#include <iostream>
using namespace std;
string findWinner(int n, int x, int y)
{
  // Write your code here .
  int dp[n + 1];
  dp[0] = 0;
  dp[1] = 1;
  for (int i = 2; i <= n; i++)
  {
    if (i - 1 >= 0 && !dp[i - 1])
      dp[i] = 1;
    else if (i - x >= 0 && !dp[i - x])
      dp[i] = 1;
    else if (i - y >= 0 && !dp[i - y])
      dp[i] = 1;
    else
    {
      dp[i] = 0;
    }
  }
  if (dp[n] != 0)
    return "Beerus";
  else
  {
    return "Whis";
  }
}

int main()
{
  int n;
  cin >> n;
  int x, y;
  cin >> x >> y;
  cout << findWinner(n, x, y) << endl;
}