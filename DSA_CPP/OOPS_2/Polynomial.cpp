#include <iostream>
using namespace std;

class Polynomial
{
  int *degCoeff;
  int capacity;

public:
  Polynomial()
  {
    this->degCoeff = new int[6];
    capacity = 5;
  }

  Polynomial(int capacity)
  {
    this->degCoeff = new int[capacity + 1];
    this->capacity = capacity;
  }

  Polynomial(Polynomial const &p)
  {
    this->degCoeff = new int[p.capacity];
    for (int i = 0; i <= p.capacity; i++)
    {
      this->degCoeff[i] = p.degCoeff[i];
    }
    this->capacity = p.capacity;
  }

  void operator=(Polynomial const &p)
  {
    this->degCoeff = new int[p.capacity + 1];
    for (int i = 0; i < p.capacity; i++)
    {
      this->degCoeff[i] = p.degCoeff[i];
    }
    this->capacity = p.capacity;
  }

  void setCoefficient(int d, int Coeff)
  {
    if (d > capacity)
    {
      int newcapacity = d;
      int *newDegCoeff = new int[newcapacity + 1];
      for (int i = 0; i <= capacity; i++)
      {
        newDegCoeff[i] = degCoeff[i];
      }
      this->degCoeff = newDegCoeff;
      this->capacity = newcapacity;
      degCoeff[d] = Coeff;
    }
    else
    {
      degCoeff[d] = Coeff;
    }
  }

  Polynomial operator+(Polynomial const &p)
  {
    int c = max(this->capacity, p.capacity);
    Polynomial pNew(c);
    for (int i = 0; i <= c; i++)
    {
      if (i <= this->capacity && i <= p.capacity)
      {
        pNew.degCoeff[i] = this->degCoeff[i] + p.degCoeff[i];
      }
      else if (i <= this->capacity)
      {
        pNew.degCoeff[i] = this->degCoeff[i];
      }
      else
        pNew.degCoeff[i] = p.degCoeff[i];
    }
    return pNew;
  }

  Polynomial operator-(Polynomial const &p)
  {
    int c = max(this->capacity, p.capacity);
    Polynomial pNew(c);
    for (int i = 0; i <= c; i++)
    {
      if (i <= this->capacity && i <= p.capacity)
      {
        pNew.degCoeff[i] = this->degCoeff[i] - p.degCoeff[i];
      }
      else if (i <= this->capacity)
      {
        pNew.degCoeff[i] = this->degCoeff[i];
      }
      else
        pNew.degCoeff[i] = -p.degCoeff[i];
    }
    return pNew;
  }

  Polynomial operator*(Polynomial const &P2)
  {

    int newcap = this->capacity + P2.capacity;
    Polynomial P3(newcap);

    for (int i = 0; i <= this->capacity; i++)
    {

      for (int j = 0; j <= P2.capacity; j++)
      {
        P3.degCoeff[i + j] += this->degCoeff[i] * P2.degCoeff[j];
      }
    }
    return P3;
  }

  void print()
  {
    for (int i = 0; i <= this->capacity; i++)
    {
      if (this->degCoeff[i] != 0)
      {
        cout << this->degCoeff[i] << "x" << i << " ";
      }
    }
    cout << endl;
  }
};