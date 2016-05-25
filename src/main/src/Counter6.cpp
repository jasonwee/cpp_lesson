#include <iostream>

class Counter
{
public:
  Counter();
  ~Counter() {}
  Counter(int newValue);
  int getValue() const { return value; }
  void setValue(int newValue) { value = newValue; }
private:
  int value;
};

Counter::Counter():
value(0)
{}

Counter::Counter(int newValue):
value(newValue)
{}

int main()
{
  int beta = 5;
  Counter alpha = beta;
  std::cout << "alpha: " << alpha.getValue() << "\n";
  return 0;
}
