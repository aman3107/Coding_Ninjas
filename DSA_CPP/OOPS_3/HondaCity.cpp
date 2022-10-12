#include "car.cpp"
class HondaCity : public Car
{
public:
  HondaCity(int x, int y) : Car(x, y)
  {
    cout << "Honda City Constructor : " << endl;
  }
  ~HondaCity()
  {
    cout << "Honda City Destructor : " << endl;
  }
};