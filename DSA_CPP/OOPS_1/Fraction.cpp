#include <iostream>
#include <cmath>
using namespace std;
class Fraction
{
  int numerator;
  int denominator;

public:
  Fraction()
  {
  }

  Fraction(int numerator, int denominator)
  {
    this->numerator = numerator;
    this->denominator = denominator;
  }

  int getNumerator() const
  {
    return numerator;
  }

  int getDenominator() const
  {
    return denominator;
  }

  void setNumerator(int numerator)
  {
    this->numerator = numerator;
  }

  void setDenominator(int denominator)
  {
    this->denominator = denominator;
  }

  void
  print()
  {
    cout << numerator << "/" << denominator << endl;
  }

  void simplfy()
  {
    int gcd = 1;
    int small = min(numerator, denominator);
    for (int i = 1; i <= small; i++)
    {
      if (numerator % i == 0 && denominator % i == 0)
      {
        gcd = i;
      }
    }
    numerator = numerator / gcd;
    denominator = denominator / gcd;
  }

  void add(const Fraction &f2)
  {
    int lcm = this->denominator * f2.denominator;
    int x = lcm / this->denominator;
    int y = lcm / f2.denominator;
    int num = x * (this->numerator) + (y * f2.numerator);
    this->numerator = num;
    this->denominator = lcm;
  }

  void multiply(Fraction const &f2)
  {
    this->numerator = this->numerator * f2.numerator;
    this->denominator = this->denominator * f2.denominator;
  }
};