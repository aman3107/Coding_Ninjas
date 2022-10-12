#include "Teacher.cpp"
#include "Student.cpp"
class TA : public Teacher, public Student
{
public:
  void print()
  {
    cout << "TA" << endl;
  }
};