#include <iostream>
using namespace std;

void spiral(int **arr, int row, int col)
{
  int sr = 0;
  int er = row - 1;
  int sc = 0;
  int ec = col - 1;
  int k = 1;
  int end = row * col;
  while (k <= end)
  {
    for (int i = sc; i <= ec && k <= end; ++i)
    {
      cout << arr[sr][i] << " ";
      k++;
    }
    sr++;
    for (int i = sr; i <= er && k <= end; ++i)
    {
      cout << arr[i][ec] << " ";
      k++;
    }
    ec--;
    for (int i = ec; i >= sc && k <= end; --i)
    {
      cout << arr[er][i] << " ";
      k++;
    }
    er--;
    for (int i = er; i >= sr && k <= end; --i)
    {
      cout << arr[i][sc] << " ";
      k++;
    }
    sc++;
  }
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
  spiral(arr, m, n);
}