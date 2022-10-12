
class Car : virtual public Vehicle
{
public:
  int numGears;

  void print()
  {
    cout << numTyres << " " << color << " " << numGears;
  }
  Car() : Vehicle(3)
  {
    cout << "Car's  Constructor " << endl;
  }

  ~Car()
  {
    cout << "Car's Default Destructor " << endl;
  }
};