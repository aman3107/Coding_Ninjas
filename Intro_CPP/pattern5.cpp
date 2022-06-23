#include<iostream>
using namespace std;

int main(){
  int n;
  cout << "Enter n : " << endl;
  cin >> n;
  int i = 1;
  while(i <= n){
    int j = 1;
    while(j <= n - i){
      cout << " ";
      j++;
    }
    int val = i;
    int k = 1;
    while(k <= i){
      cout << val;
      val++;
      k++;
    }
    cout << endl;
    i++;
  }
}