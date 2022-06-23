#include<iostream>
using namespace std;

int main(){
  int n;
  cout << "Enter the number : " << endl;
  cin >> n;
  int d = 2;
  bool prime = true;
  while(d < n){
    if(n % d == 0)
      prime = false;
    d++;
  }
  if(prime == true)
    cout << "Prime : " << endl;
  else
    cout << "Not Prime : " << endl;
}