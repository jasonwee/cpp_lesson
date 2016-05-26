#include <iostream>

enum BREED { YORKIE, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };

class Mammal
{
public:
  // constructors
  Mammal();
  Mammal(int age);
  ~Mammal();

  // accessors
  int getAge() const { return age; }
  void setAge(int newAge) { age = newAge; }
  int getWeight() const { return weight; }
  void setWeight(int newWeight) { weight = newWeight; }

  // other methods
  void speak() const { std::cout << "Mammal sound!\n"; }
  void sleep() const { std::cout << "Shhh. I'm sleeping . \n"; }

protected:
  int age;
  int weight;
};

class Dog : public Mammal
{
public:
  // constructors
  Dog();
  Dog(int age);
  Dog(int age, int weight);
  Dog(int age, BREED breed);
  Dog(int age, int weight, BREED breed);
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

Mammal::Mammal(int age):
age(age),
weight(5)
{
  std::cout << "Mammal(int) constructor ...\n";
}

Mammal::~Mammal()
{
  std::cout << "Mammal destructor ...\n";
}

Dog::Dog():
Mammal(),
breed(YORKIE)
{
  std::cout << "Dog constructor ...\n";
}

Dog::Dog(int age):
Mammal(age),
breed(YORKIE)
{
  std::cout << "Dog(int) constructor ...\n";
}

Dog::Dog(int age, int newWeight):
Mammal(age),
breed(YORKIE)
{
  weight = newWeight;
  std::cout << "Dog(int, int) constructor ...\n";
}

Dog::Dog(int age, int newWeight, BREED breed):
Mammal(age),
breed(breed)
{
  weight = newWeight;
  std::cout << "Dog(int, int, BREED) constructor ...\n";
}

Dog::Dog(int age, BREED newBreed):
Mammal(age),
breed(newBreed)
{
  std::cout << "Dog(int, BREED) constructor ...\n";
}

Dog::~Dog()
{
  std::cout << " Dog destructor ...\n";
}

int main()
{
  Dog fido;
  Dog rover(5);
  Dog buster(6, 8);
  Dog yorkie(3, YORKIE);
  Dog dobbie(4, 20, DOBERMAN);
  fido.speak();
  rover.wagTail();
  std::cout << "Yorkie is "
      << yorkie.getAge() << " years old\n";
  std::cout << "Dobbie weighs "
      << dobbie.getWeight() << " pounds\n";
  return 0;
}
