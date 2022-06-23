#include<iostream>
using namespace std;

int main(){
  char c;
  cout << "Enter the character : " << endl;
  cin >> c;

  if(c >= 65 && c <=90)
    cout << "UpperCase : " << endl;
  else if(c >= 97 && c <= 122)
    cout << "LowerCase : " << endl;
  else
    cout << "Not an Alphabet : " << endl;
}