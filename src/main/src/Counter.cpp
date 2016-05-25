#include <iostream>

class Counter
{
public:
  Counter();
  ~Counter() {}
  int getValue() const { return value; }
  void setValue(int x) { value = x; }

private:
  int value;
};

Counter::Counter():
value(0)
{}

int main()
{
  Counter c;
  std::cout << "The value of c is " << c.getValue()
      << "\n";
  return 0;
}
