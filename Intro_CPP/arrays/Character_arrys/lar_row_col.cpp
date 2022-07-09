#include <iostream>
#include <climits>
using namespace std;

void lar_row_col(int **arr, int m, int n)
{
  int max = INT_MIN;
  int index;
  string s;
  for (int i = 0; i < m; i++)
  {
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
      sum = sum + arr[i][j];
    }
    if (sum > max)
    {
      max = sum;
      index = i;
      s = "row";
    }
  }
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = 0; j < m; j++)
    {
      sum = sum + arr[j][i];
    }
    if (sum > max)
    {
      max = sum;
      index = i;
      s = "coloumn";
    }
  }
  cout << s << " " << index << " " << max << endl;
}

int main()
{
  int m, n;
  cout << "Enter rows and columns : " << endl;
  cin >> m >> n;
  int **arr;
  arr = new int *[m];
  for (int i = 0; i < m; i++)
  {
    arr[i] = new int[n];
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];
  }
  lar_row_col(arr, m, n);
}