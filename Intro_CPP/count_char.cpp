#include <iostream>
using namespace std;

int main()
{
  char c;
  int c_char = 0;
  int c_num = 0;
  int c_space = 0;
  while (c != '$')
  {
    c = cin.get();

    if (c >= 97 && c <= 122)
      c_char++;
    else if (c >= 48 && c <= 57)
      c_num++;
    else if (c == ' ' || c == '\n' || c == '\t')
      c_space++;
  }
  cout << c_char << " " << c_num << " " << c_space << endl;
}