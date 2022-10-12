#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
  int maxSpeed;

protected:
  int numTyres;

public:
  string color;

  Vehicle()
  {
    cout << "Vehicle's Default Constructor " << endl;
  }

  Vehicle(int z)
  {
    cout << "Vehicle's Parametrized Constructor : " << endl;
    maxSpeed = z;
  }

  ~Vehicle()
  {
    cout << "Vehicle's Default Destructor " << endl;
  }

  void print()
  {
    cout << "Hello Aman " << endl;
  }
};