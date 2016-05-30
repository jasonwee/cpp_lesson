#include <iostream>

enum BOOL {FALSE, TRUE};

class Mammal
{
public:
  Mammal():age(1) { }
  virtual ~Mammal() { }
  virtual void speak() const = 0;
  virtual void move() const = 0;
protected:
  int age;
};

class Dog : public Mammal
{
public:
  void speak() const { std::cout << "Woof!\n"; }
  void move() const { std::cout << "Walking to heel ...\n"; }
};

class Cat : public Mammal
{
public:
  void speak() const { std::cout << "Meow!\n"; }
  void move() const { std::cout << "Slinking...\n"; }
};

class Horse : public Mammal
{
public:
  void speak() const { std::cout << "Winnie!\n"; }
  void move() const { std::cout << "Galloping ...\n"; }
};

int main()
{
  void (Mammal::*pFunc)() const = 0;
  Mammal* ptr = 0;
  int animal; 
  int method;
  bool fQuit = false;

  while (fQuit == false)
  {
    std::cout << "(0) Quit (1) Dog (2) Cat (3) Horse: ";
    std::cin >> animal;
    switch (animal)
    {
    case 1:
      ptr = new Dog;
      break;
    case 2:
      ptr = new Cat;
      break;
    case 3:
      ptr = new Horse;
      break;
    default:
      fQuit = true;
      break;
    }
    if (fQuit)
      break;

    std::cout << "(1) Speak (2) Move: ";
    std::cin >> method;
    switch (method)
    {
    case 1: 
      pFunc = &Mammal::speak;
      break;
    default:
      pFunc = &Mammal::move;
      break;
    }

    (ptr->*pFunc)();
    delete ptr;
  }
  return 0;
}
