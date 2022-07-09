#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  char ch[1000];
  cout << "Enter characters : " << endl;
  cin.getline(ch, 1000);
  for (int i = 0; ch[i] != '\0'; i++)
  {
    for (int j = 0; ch[j] != '\0'; j++)
    {
      for (int k = i; k <= j; k++)
        cout << ch[k] << " ";
      cout << endl;
    }
  }
}