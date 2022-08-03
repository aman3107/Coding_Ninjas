#include <iostream>
using namespace std;

int subset(int input[], int n, int output[][20])
{
  if (n == 0)
  {
    output[0][0] = 0;
    return 1;
  }
  int smallOutput = subset(input + 1, n - 1, output);
  for (int i = 0; i < smallOutput; i++)
  {
    output[i + smallOutput][0] = output[i][0] + 1;
    for (int j = (output[i][0] + 1); j > 1; j--)
    {
      output[i + smallOutput][j] = output[i][j - 1];
    }
    output[i + smallOutput][1] = input[0];
  }
  return 2 * smallOutput;
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int input[20];
  int output[1000][20];
  for (int i = 0; i < n; i++)
    cin >> input[i];

  int size = subset(input, n, output);

  for (int i = 0; i < size; i++)
  {
    for (int j = 1; j <= output[i][0]; j++)
    {
      cout << output[i][j] << " ";
    }
    cout << endl;
  }
}