#include <iostream>
#include "Fraction.cpp"
using namespace std;

int main()
{
  Fraction f1(10, 2);
  Fraction f2(15, 4);
  f1.multiply(f2);
  f1.simplfy();
  f1.print();

  Fraction const f3;
  cout << f3.getNumerator() << " " << f3.getDenominator() << endl;
}