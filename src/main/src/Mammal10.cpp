#include <iostream>

class Mammal
{
public:
  Mammal():age(1) { }
  ~Mammal() { }
  virtual void speak() const { std::cout << "Mammal speak!\n"; }
protected:
  int age;
};

class Dog : public Mammal
{
public:
  void speak() const { std::cout << "Woof!\n"; }
}; 

class Cat : public Mammal
{
public:
  void speak() const { std::cout << "Meow!\n"; }
};

void valueFunction(Mammal);
void ptrFunction(Mammal*);
void refFunction(Mammal&);

int main()
{
  Mammal* ptr = 0;
  int choice;
  while (1)
  {
    bool fQuit = false;
    std::cout << "(1) dog (2) cat (0) quit: ";
    std::cin >> choice;
    switch (choice)
    {
    case 0:
      fQuit = true;
      break;
    case 1:
      ptr = new Dog;
      break;
    case 2:
      ptr = new Cat;
      break;
    default:
      ptr = new Mammal;
      break;
    }
    if (fQuit)
    {
      break;
    }
    ptrFunction(ptr);
    refFunction(*ptr);
    valueFunction(*ptr);
  }
  return 0;
}

void valueFunction(Mammal mammalValue) // this function is called last
{
  mammalValue.speak();
}

void ptrFunction(Mammal *pMammal)
{
  pMammal-> speak();
}

void refFunction(Mammal &rMammal)
{
  rMammal.speak();
}
