#include <iostream>

class SimpleCat
{
public:
  SimpleCat(int cat, int weight);
  ~SimpleCat() {}
  int GetAge() {return itsAge;}
  int GetWeight() {return itsWeight;}

private:
  int itsAge;
  int itsWeight;
};

SimpleCat::SimpleCat(int age, int weight):
itsAge(age), itsWeight(weight) {}

SimpleCat & TheFunction();

int main()
{
  SimpleCat &rCat = TheFunction();
  int age = rCat.GetAge();
  std::cout << "rCat is " << age << " years old!\n";
  std::cout << "&rCat: " << &rCat << "\n";
  // how do you get rid of that memory?
  SimpleCat *pCat = &rCat;
  delete pCat;
  // uh oh, rCat now refers to ??
  return 0;
}

SimpleCat &TheFunction()
{
  SimpleCat *pFrisky = new SimpleCat(5,9);
  std::cout << "pFrisky: " << pFrisky << "\n";
  return *pFrisky;
}
