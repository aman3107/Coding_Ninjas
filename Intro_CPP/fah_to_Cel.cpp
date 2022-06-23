#include<iostream>
using namespace std;

int main(){
  int sf,ef,ss;
  cout << "Enter start Fahrenheit end Fahrenheit and step size : " <<endl;
  cin >> sf >> ef >> ss;
  while(sf <= ef){
    int cel = 5.0/9*(sf - 32);
    cout << sf << " " << cel << endl;
    sf += ss;
  }
}