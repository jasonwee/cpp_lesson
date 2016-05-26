#include <iostream>

enum BREED { YORKIE, CAIRN, DANDIE, SHETLAND, DOBERMAN, LAB };

class Mammal
{
public:
  // constructors
  Mammal() { std::cout << "Mammal constructor ...\n"; }
  ~Mammal() { std::cout << "Mammal destructor ...\n"; }

  // other methods
  void speak() const { std::cout << "Mammla sound!\n"; }
  void sleep() const { std::cout << "Shhh. I'm sleeping. \n"; }

protected:
  int age;
  int weight;
};

class Dog : public Mammal
{
public:
  // constructors
  Dog() { std::cout << "Dog constructor ...\n"; }
  ~Dog() { std::cout << "Dog destructor ...\n"; }

  // other methods
  void wagTail() { std::cout << "Tail wagging ...\n";}
  void begForFood() { std::cout << "Begging for food ...\n"; }
  void speak() const { std::cout << "Woof!\n"; }

private:
  BREED breed;
};

int main()
{
  Mammal bigAnimal;
  Dog fido;
  bigAnimal.speak();
  fido.speak();
  return 0;
}
