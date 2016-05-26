#include <iostream>

enum BREED { YORKIE, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };

class Mammal
{
public:
  // constructors
  Mammal();
  ~Mammal();

  // accessors
  int getAge() const { return age; }
  void setAge(int newAge) { age = newAge; }
  int getWeight() const { return weight; }
  void setWeight(int newWeight) { weight = newWeight; }

  // other methods
  void speak() const { std::cout << "Mammal sound!\n"; }
  void sleep() const { std::cout << "shhh. I'm sleeping.\n"; }

protected:
  int age;
  int weight;
};

class Dog: public Mammal
{
public:
  // constructors
  Dog();
  ~Dog();

  // accessors
  BREED getBreed() const { return breed; }
  void setBreed(BREED newBreed) { breed = newBreed; }

  // other methods
  void wagTail() { std::cout << "Tail wagging ...\n"; }
  void begForFood() { std::cout << "Begging for food ...\n"; }

private:
  BREED breed;
};

Mammal::Mammal():
age(1),
weight(5)
{
  std::cout << "Mammal constructor ...\n";
}

Mammal::~Mammal()
{
  std::cout << "Mammal destructor ...\n";
}

Dog::Dog():
breed(YORKIE)
{
  std::cout << "Dog constructor ...\n";
}

Dog::~Dog()
{
  std::cout << "Dog destructor ...\n";
}

int main()
{
  Dog fido; // create a dog
  fido.speak();
  fido.wagTail();
  std::cout << "Fido is " << fido.getAge() << " years old\n";
  return 0;
}
