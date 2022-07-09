#include <iostream>
using namespace std;

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

  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = 0; j < m; j++)
    {
      sum = sum + arr[j][i];
    }
    cout << sum << endl;
  }
}