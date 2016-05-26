#include <iostream>

class Mammal
{
public:
  Mammal():age(1) { std::cout << "Mammal constructor ...\n"; }
  virtual ~Mammal() { std::cout << "Mammal destructor ...\n"; }
  virtual void speak() const { std::cout << "Mammal speak!\n"; }
protected:
  int age;
};

class Cat : public Mammal
{
public:
  Cat() { std::cout << "Cat constructor ...\n"; }
  ~Cat()  { std::cout << "Cat destructor ...\n"; }
  void speak() const { std::cout << "Meow!\n"; }
};

int main()
{
  Mammal *pCat = new Cat;
  pCat->speak();
  return 0;
}
