#include <iostream>
#include <vector>
using namespace std;

void PrintSubsetSumToK(int input[], int size, int k, vector<int> output)
{
  if (size == 0)
  {
    if (k == 0)
    {
      for (int i : output)
      {
        cout << i << " ";
      }
      cout << endl;
    }
    return;
  }

  PrintSubsetSumToK(input + 1, size - 1, k, output);
  output.push_back(input[0]);
  PrintSubsetSumToK(input + 1, size - 1, k - input[0], output);
}

void printSubsetSumToK(int input[], int size, int k)
{
  vector<int> output;
  PrintSubsetSumToK(input, size, k, output);
}

int main()
{
  int input[1000], length, k;
  cin >> length;
  for (int i = 0; i < length; i++)
    cin >> input[i];
  cin >> k;
  printSubsetSumToK(input, length, k);
}