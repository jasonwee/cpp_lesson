#include <iostream>

class Mammal
{
public:
  Mammal():age(1) { std::cout << "Mammal constructor ...\n"; }
  ~Mammal() { std::cout << "Mammal destructor ...\n"; }
  void move() const { std::cout << "Mammal, move one step\n"; }
  virtual void speak() const { std::cout << "Mammal speak!\n"; }

protected:
  int age;
};

class Dog : public Mammal
{
public:
  Dog() { std::cout << "Dog constructor ...\n"; }
  ~Dog() { std::cout << "Dog destructor ...\n"; }
  void wagTail() { std::cout << "Wagging tail ...\n"; }
  void speak() const { std::cout << "Woof!\n"; }
  void move() const { std::cout << "Dog moves 5 steps ...\n"; }
}; 

int main()
{
  Mammal *pDog = new Dog;
  pDog->move();
  pDog->speak();
  return 0;
}
