#include <iostream>

enum BREED { YORKIE, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };

class Mammal
{
public:
  // constructors
  Mammal(): age(2), weight(5) {}
  ~Mammal() {}

  // accessors
  int getAge() const { return age; }
  void setAge(int newAge) { age = newAge; }
  int getWeight() const { return weight; }
  void setWeight(int newWeight) { weight = newWeight; }

  // other methods
  void speak() const { std::cout << "Mammal sound!\n"; }
  void sleep() const { std::cout << "Shhh. I'm sleeping. \n"; }

protected:
  int age;
  int weight;
};

class Dog: public Mammal
{
public:
  // constructors
  Dog(): breed(YORKIE) {}
  ~Dog() {}

  // accessors
  BREED getBreed() const { return breed; }
  void setBreed(BREED newBreed) { breed = newBreed; }

  // other methods
  void wagTail() { std::cout << "Tail wagging ...\n"; }
  void begForFood() { std::cout << "Begging for food ...\n"; }

private:
  BREED breed;
};

int main()
{
  Dog fido;
  fido.speak();
  fido.wagTail();
  std::cout << "Fido is " << fido.getAge() << " years old\n";
  return 0;
}
