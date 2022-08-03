#include <iostream>
#include <string>
using namespace std;

int returnPermutations(string input, string output[])
{
  if (input.size() == 1)
  {
    output[0] = input[0];
    return 1;
  }

  int index = 0;
  string smallOutput[10000];
  for (int i = 0; i < input.size(); i++)
  {
    int ans = returnPermutations(input.substr(0, i) + input.substr(i + 1, input.size() - i - 1), smallOutput);
    for (int j = 0; j < ans; j++)
    {
      output[index++] = input[i] + smallOutput[j];
    }
  }
  return index;
}

int main()
{
  string input;
  cin >> input;
  string output[10000];
  int count = returnPermutations(input, output);
  for (int i = 0; i < count && i < 10000; i++)
  {
    cout << output[i] << endl;
  }
  return 0;
}