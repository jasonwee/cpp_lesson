#include <iostream>

class Mammal
{
public:
  Mammal():age(1) { std::cout << "Mammal constructor ...\n"; }
  virtual ~Mammal() { std::cout << "Mammal destructor ...\n"; }
  Mammal(const Mammal &rhs);
  virtual void speak() const { std::cout << "Mammal speak!\n"; }
  virtual Mammal* clone() { return new Mammal(*this); }
  int getAge() const { return age; }

protected:
  int age;
};

Mammal::Mammal(const Mammal &rhs):age(rhs.getAge())
{
  std::cout << "Mammal copy constructor ...\n";
}

class Dog : public Mammal
{
public:
  Dog() { std::cout << "Dog constructor ...\n"; }
  virtual ~Dog() { std::cout << "Dog destructor ..\n"; }
  Dog (const Dog &rhs);
  void speak() const { std::cout << "Woof!\n"; }
  virtual Mammal* clone() { return new Dog(*this); }
};

Dog::Dog(const Dog &rhs):
Mammal(rhs)
{
  std::cout << "Dog copy constructor ...\n";
}

class Cat : public Mammal
{
public:
  Cat() { std::cout << "Cat constructor ...\n"; }
  virtual ~Cat()  { std::cout << "Cat destructor ...\n"; }
  Cat (const Cat&);
  void speak() const { std::cout << "Meow!\n"; }
  virtual Mammal* Clone() { return new Cat(*this); }
};

Cat::Cat(const Cat &rhs):
Mammal(rhs)
{
  std::cout << "Cat copy constructor ...\n";
}

enum ANIMALS { MAMMAL, DOG, CAT};
const int numAnimalTypes = 3;
int main()
{
  Mammal *array[numAnimalTypes];
  Mammal *ptr;
  int choice, i;
  for (i = 0; i < numAnimalTypes; i++)
  {
    std::cout << "(1) dog (2) cat (3) mammal: ";
    std::cin >> choice;
    switch (choice)
    {
    case DOG:
      ptr = new Dog;
      break;
    case CAT:
      ptr = new Cat;
      break;
    default:
      ptr = new Mammal;
      break;
    }
    array[i] = ptr;
  }
  Mammal *otherArray[numAnimalTypes];
  for (i=0; i < numAnimalTypes; i++)
  {
    array[i] -> speak();
    otherArray[i] = array[i] -> clone();
  }
  for (i=0; i < numAnimalTypes; i++)
  {
    otherArray[i]->speak();
  }
  return 0;
}
