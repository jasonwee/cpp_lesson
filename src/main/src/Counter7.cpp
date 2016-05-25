#include <iostream>

class Counter
{
public:
  Counter();
  ~Counter() {}
  Counter(int newValue);
  int getValue() const { return value; }
  void setValue(int newValue) { value = newValue; }
  operator unsigned int();
private:
  int value;
};

Counter::Counter():
value(0)
{}

Counter::Counter(int newValue):
value(newValue)
{}

Counter::operator unsigned int()
{
 return (value);
}

int main()
{
  Counter epsilon(19);
  int zeta = epsilon;
  std::cout << "zeta: " << zeta << "\n";
  return 0;
}
