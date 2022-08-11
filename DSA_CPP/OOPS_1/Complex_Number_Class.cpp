#include <iostream>
using namespace std;

class ComplexNumbers
{
  int real, imag;

public:
  ComplexNumbers(int real, int imag)
  {
    this->real = real;
    this->imag = imag;
  }

  void plus(ComplexNumbers const &c2)
  {
    this->real = this->real + c2.real;
    this->imag = this->imag + c2.imag;
  }
  void multiply(ComplexNumbers const &c2)
  {
    int x = this->real * c2.real - (this->imag * c2.imag);
    int y = this->real * c2.imag + (this->imag * c2.real);
    this->real = x;
    this->imag = y;
  }

  void print()
  {
    cout << this->real << " + i" << this->imag << endl;
  }
};

int main()
{
  int real1, imaginary1, real2, imaginary2;
  cin >> real1 >> imaginary1;
  cin >> real2 >> imaginary2;

  ComplexNumbers c1(real1, imaginary1);
  ComplexNumbers c2(real2, imaginary2);

  int choice;
  cin >> choice;

  if (choice == 1)
  {
    c1.plus(c2);
    c1.print();
  }
  else if (choice == 2)
  {
    c1.multiply(c2);
    c1.print();
  }
  else
  {
    return 0;
  }
}