#include <iostream>
#include <string.h>
using namespace std;

void printAllPossibleCodes(string input, string output = "")
{
  if (input.size() == 0)
  {
    cout << output << endl;
    return;
  }

  char c1 = (input[0] - 48) + 96;
  if (input[0] == '0')
    return;
  printAllPossibleCodes(input.substr(1), output + c1);

  if (input.size() > 1)
  {
    int d = (input[0] - 48) * 10 + (input[1] - 48);
    if (d > 26)
      return;
    char c2 = d + 96;
    printAllPossibleCodes(input.substr(2), output + c2);
  }
}

int main()
{
  string input;
  cin >> input;

  printAllPossibleCodes(input);
}