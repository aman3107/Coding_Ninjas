#include<iostream>
using namespace std;

int main(){
  int n;
  cout << "Enter n " << endl;
  cin >> n;
  int soe = 0, soo = 0;
  while(n > 0){
    int rem = n % 10;
    if(rem % 2 == 0){
      soe += rem;
    }
    else{
      soo += rem;
    }
    n = n / 10;
  }
  cout << soe <<  " " << soo << endl ;
}