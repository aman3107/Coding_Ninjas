#include <iostream>
using namespace std;

int length(char input[])
{
  int i = 0;
  while (input[i] != '\0')
  {
    i++;
  }
  return i;
}

int main()
{
  char name[100];
  cout << "Enter your name : " << endl;
  cin >> name;
  cout << "Name : " << name << endl;
  int ans = length(name);
  cout << ans << endl;
}