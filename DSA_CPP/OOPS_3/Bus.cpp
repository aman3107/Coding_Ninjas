class Bus : public Car, public Truck
{
public:
  Bus() : Vehicle(5)
  {
    cout << "Bus's Constructor : " << endl;
  }
};