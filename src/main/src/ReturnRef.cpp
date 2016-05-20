#include <iostream>

/* this is an example of reference use incorrectly
 *
 */
class SimpleCat
{
public:
  SimpleCat(int age, int weight);
  ~SimpleCat() {}
  int GetAge() { return itsAge; }
  int GetWeight() { return itsWeight; }
private:
  int itsAge;
  int itsWeight;
};

SimpleCat::SimpleCat(int age, int weight):
itsAge(age), itsWeight(weight) {}

SimpleCat &TheFunction();

int main()
{
  SimpleCat &rCat = TheFunction();
  int age = rCat.GetAge();
  std::cout << "rCat is " << age >> " years old!\n";
  return 0;
}

SimpleCat &TheFunction()
{
  SimpleCat Frisky(5,9);
  return Frisky;
}
