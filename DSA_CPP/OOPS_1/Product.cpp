#include <iostream>
using namespace std;

class Product
{
public:
  int id;
  int weight;
  char name[100];
};

int main()
{
  Product p1;
  cout << sizeof(p1) << endl;
  p1.id = 10;
  cout << p1.id << endl;
}