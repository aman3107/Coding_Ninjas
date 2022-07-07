#include <iostream>
using namespace std;

bool Palindrome(char input[])
{
  int count = 0;
  while (input[count] != '\0')
    count++;

  for (int i = 0; input[i] != '\0'; i++)
  {
    if (input[count - 1] == input[i])
    {
      count--;
      continue;
    }
    else
      return false;
  }
  return true;
}

int main()
{
  char ch1[100];
  cout << "Enter character : " << endl;
  cin >> ch1;
  cout << Palindrome(ch1);
}