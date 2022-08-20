#include <iostream>
using namespace std;

class Student2
{
  static int totalStudents;

public:
  int age;
  int rollNumber;

  Student2()
  {
    totalStudents++;
  }

  int getrollNumber()
  {
    return rollNumber;
  }

  int getAge()
  {
    return age;
  }

  static int getTotalStudents()
  {
    return totalStudents;
  }
};

int Student2 ::totalStudents = 0;