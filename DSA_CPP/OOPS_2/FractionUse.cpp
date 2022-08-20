#include <iostream>
#include "Fraction.cpp"
using namespace std;

int main()
{
  Fraction f1(10, 2);
  Fraction f2(15, 4);
  Fraction f3 = f1.add(f2);
  f1.print();
  f2.print();
  f3.print();
  Fraction f4 = f1 + f2;
  f4.print();
  Fraction f5 = f1 * f2;
  f5.print();
  if (f1 == f1)
    cout << "Equal" << endl;
  else
    cout << "Not Equal" << endl;
  // ++f1;
  // f1.print();
  // Fraction f6 = ++(++f1);
  // f1.print();
  // f6.print();

  Fraction f6 = f1++;
  f1.print();
  f6.print();

  Fraction f7(10, 3);
  Fraction f8(5, 2);
  (f7 += f8) += f8;
  f7.print();
}