#include <iostream>
#include <cstring>
using namespace std;

bool palindrome(char input[])
{
  static int i = 0;
  int j = strlen(input);
  if (i >= j)
    return true;

  if (input[i] != input[j - i - 1])
  {
    return false;
  }
  else
  {
    i++;
    palindrome(input);
  }
}

int main()
{
  char input[50];
  cin >> input;

  if (palindrome(input))
    cout << "true" << endl;
  else
    cout << "false" << endl;
}