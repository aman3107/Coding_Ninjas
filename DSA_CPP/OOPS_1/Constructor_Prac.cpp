#include <iostream>
#include "student.cpp"
using namespace std;

int main()
{
  Student s1;         // Contructor Called
  Student s2(01);     // Constructor 2 called
  Student s3(10, 02); // COnstructor 4 called

  Student s4(s3); // Copy Constructor

  s1 = s2; // Copy assignment operator
}