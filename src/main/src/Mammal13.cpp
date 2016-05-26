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
  void purr() const { std::cout  << "Rrrrrrr!\n"; }
};

class Dog: public Mammal
{
public:
  Dog() { std::cout << "Dog constructor ...\n"; }
  ~Dog() { std::cout << "Dog destructor ...\n"; }
  void speak() const { std::cout << "Woof!\n"; }
};

int main()
{
  const int numberMammals = 3;
  Mammal* zoo[numberMammals];
  Mammal* pMammal;
  int choice, i;
  for (i=0; i < numberMammals; i++)
  {
    std::cout << "(1)Dog (2)Cat: ";
    std::cin >> choice;
    if (choice == 1)
      pMammal = new Dog;
    else
     pMammal = new Cat;

    zoo[i] = pMammal;
  }
  
  std::cout << "\n";

  for (i = 0; i < numberMammals; i++)
  {
    zoo[i] -> speak();

    Cat *pRealCat = dynamic_cast<Cat *> (zoo[i]);
    if (pRealCat)
      pRealCat->purr();
    else
      std::cout << "Uh oh , not a cat!\n";

    delete zoo[i];
    std::cout << "\n";
  }

  return 0;
}
