#include <iostream>
#include <climits>
using namespace std;

void high_occur(char ch[])
{
  int hash[26] = {0};
  for (int i = 0; ch[i] != '\0'; i++)
  {
    hash[ch[i] - 'a']++;
  }
  int max = INT_MIN;
  char ans;
  for (int i = 0; i < 26; i++)
  {
    if (hash[i] > max)
    {
      max = hash[i];
      ans = 'a' + i;
    }
  }
  cout << ans << endl;
}

int main()
{
  char ch[1000];
  cout << "Enter characters : " << endl;
  cin.getline(ch, 1000);
  high_occur(ch);
}