#include <iostream>

/*
 * you cannot assign int to Counter object, just cannot
 * compile
 */
class Counter
{
public:
  Counter();
  ~Counter() {}
  int getValue() const { return value; }
  void setValue(int newValue) { value = newValue; }
private:
  int value;
};

Counter::Counter():
value(0)
{}

int main()
{
  int beta = 5;
  Counter alpha = beta;
  std::cout << "alpha: " << alpha.getValue() << "\n";
  return 0;
}
