#include <iostream>

class Counter
{
public:
  Counter();
  ~Counter(){}
  int getValue() const { return value; }
  void setValue(int x) { value = x; }
  void increment() { ++value; }
  const Counter& operator++();

private:
  int value;
};

Counter::Counter():
value(0)
{}

const Counter& Counter::operator++()
{
  ++value;
  return *this;
}

int main()
{
  Counter c;
  std::cout << "The value of c is " << c.getValue() 
      << "\n";
  c.increment();
  std::cout << "The value of c is " << c.getValue()
      << "\n";
  ++c;
  std::cout << "The value of c is " << c.getValue()
      << "\n";
  Counter a = ++c;
  std::cout << "The value of a: " << a.getValue();
  std::cout << " and c: " << c.getValue() << "\n";
  return 0;
}
