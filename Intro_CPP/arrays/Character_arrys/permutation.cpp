#include <iostream>
using namespace std;

bool permutation(char ch[], char ch1[])
{
  int hash1[26] = {0};
  int hash2[26] = {0};
  for (int i = 0; ch[i] != '\0'; i++)
  {
    hash1[ch[i] - 'a']++;
    hash2[ch1[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++)
  {
    if (hash1[i] != hash2[i])
      return false;
  }
  return true;
}

int main()
{
  char ch[1000];
  cout << "Enter characters : " << endl;
  cin.getline(ch, 1000);
  char ch1[1000];
  cout << "Enter characters : " << endl;
  cin.getline(ch1, 1000);
  bool ans = permutation(ch, ch1);
  cout << ans << endl;
}