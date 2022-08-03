#include <iostream>
#include <string>
using namespace std;

void printPermutation(string input, string output = "")
{
  if (input.size() == 0)
  {
    cout << output << endl;
    return;
  }
  for (int i = 0; i < input.size(); i++)
  {
    string str = input.substr(0, i) + input.substr(i + 1, input.size());
    printPermutation(str, output + input[i]);
  }
}

int main()
{
  string input;
  cin >> input;
  printPermutation(input);
}