#include <iostream>
using namespace std;

void printSubsetsOfArray(int input[], int ei, int si, int output[], int l)
{
  if (si == ei)
  {
    for (int i = 0; i < l; i++)
    {
      cout << output[i] << " ";
    }
    cout << endl;
    return;
  }

  int temp[1000];
  printSubsetsOfArray(input, ei, si + 1, output, l);
  int i;
  for (i = 0; i < l; i++)
  {
    temp[i] = output[i];
  }
  temp[i] = input[si];
  printSubsetsOfArray(input, ei, si + 1, temp, l + 1);
}

int main()
{
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int input[1000];
  for (int i = 0; i < n; i++)
    cin >> input[i];
  int output[1000];
  printSubsetsOfArray(input, n, 0, output, 0);
}