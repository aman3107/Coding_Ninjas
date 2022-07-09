#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  char ch[100];
  cout << "Enter characters : " << endl;
  cin.getline(ch, 100);
  int len = strlen(ch);
  cout << len << endl;
  char ch2[100];
  cout << "Enter second character : " << endl;
  cin.getline(ch2, 100);
  int ans = strcmp(ch, ch2);
  cout << ans << endl;
  strcpy(ch, ch2);
  cout << ch << endl;
}