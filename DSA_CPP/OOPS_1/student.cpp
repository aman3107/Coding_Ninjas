#include <iostream>
using namespace std;

class Student
{
public:
  string name;
  int rollNumber;

private:
  int age;

public:
  // Default Constructor

  ~Student()
  {
    cout << "Destructor Called : " << endl;
  }

  Student()
  {
    cout << "Constructor Called : " << endl;
  }

  Student(int rollNumber)
  {
    cout << "This : " << this << endl;
    cout << "Construtor 2 called : " << endl;
    this->rollNumber = rollNumber;
  }

  Student(int a, string s)
  {
    cout << "Constructor 3 called : " << endl;
    age = a;
    name = s;
  }

  Student(int x, int y)
  {
    cout << "Constructor 4 called " << endl;
    age = x;
    rollNumber = y;
  }

  void display()
  {
    cout << age << " " << rollNumber << endl;
  }

  int getAge()
  {
    return age;
  }

  void setAge(int a)
  {
    if (a < 0)
      return;
    age = a;
  }
};