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

class Horse : public Mammal
{
public:
  void speak() const { std::cout << "Whinny!\n"; }
}; 

class Pig : public Mammal
{
public:
  void speak() const { std::cout << "Oink!\n"; }
}; 

int main()
{
  Mammal* array[5];
  Mammal* ptr;
  int choice, i;
  for (i=0; i < 5; i++)
  {
    std::cout << "(1) dog (2) cat (3) horse (4) pig: ";
    std::cin >> choice;
    switch (choice)
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
    case 4:
      ptr = new Pig;
      break;
    default:
      ptr = new Mammal;
      break;
    }
    array[i] = ptr;
  }
  for (i=0; i < 5; i++)
  {
    array[i]->speak();
  }
  return 0;
}
