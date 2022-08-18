#include <iostream>
#include <cstring>
using namespace std;

class StudentC
{
public:
  int age;
  const int rollNumber;

  StudentC(int r) : rollNumber(r) {}

  void display()
  {
    cout << age << " " << rollNumber << endl;
  }
};