#include <iostream>

class SimpleCat {
public:
  SimpleCat() {itsAge = 2;}
  ~SimpleCat(){}
  int GetAge() const { return itsAge; }
  void SetAge(int age) { itsAge = age; }
private:
  int itsAge;
};

int main() {
  SimpleCat *Frisky = new SimpleCat;
  std::cout << "Frisky is " << Frisky->GetAge() << " years old" << "\n";

  Frisky->SetAge(5);
  std::cout << "Frisky is " << Frisky->GetAge() << " years old\n";

  delete Frisky;
  return 0;
}
