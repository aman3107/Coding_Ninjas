#include <iostream>
#include "QueueUSingArray.cpp"
using namespace std;

int main()
{
  Queue<int> q1(5);
  q1.enqueue(10);
  q1.enqueue(20);
  q1.enqueue(30);
  cout << q1.dequeue() << endl;
  cout << q1.getSize() << endl;
  cout << q1.front() << endl;
  q1.enqueue(40);
  q1.enqueue(50);
  q1.enqueue(60);
  q1.enqueue(70);
  cout << q1.dequeue() << endl;
  cout << q1.dequeue() << endl;
  cout << q1.dequeue() << endl;
  cout << q1.dequeue() << endl;
  cout << q1.dequeue() << endl;
  cout << q1.getSize() << endl;
  cout << q1.isEmpty() << endl;
  cout << q1.front() << endl;
}