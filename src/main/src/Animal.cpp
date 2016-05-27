#include <iostream>

enum COLOR { Red, Green, Blue, Yellow, White, Black, Brown };

class Animal // common base to both horse and bird
{
public:
  Animal(int);
  virtual ~Animal() { std::cout << "Animal destructor ...\n"; }
  virtual int getAge() const { return age; }
  virtual void setAge(int newAge) { age = newAge;}
  virtual void sleep() const = 0;
  virtual void eat() const = 0;
  virtual void reproduce() const = 0;
  virtual void move() const = 0;
  virtual void speak() const = 0;
private:
  int age;
};

Animal::Animal(int newAge):
age(newAge)
{
  std::cout << "Animal constructor ...\n";
}

class Mammal : public Animal
{
public:
  Mammal(int newAge):Animal(newAge)
    { std::cout << "Mammal constructor ...\n";}
  virtual ~Mammal() { std::cout << "Mammal destructor ...\n";}
  virtual void reproduce() const
    { std::cout << "Mammal reproduction depicted ...\n"; }
};

class Fish : public Animal
{
public:
  Fish(int newAge):Animal(newAge)
    { std::cout << "Fish constructor ...\n";}
  virtual ~Fish()
    { std::cout << "Fish destructor ...\n"; }
  virtual void sleep() const 
    { std::cout << "Fish snoring ...\n"; }
  virtual void eat() const
    { std::cout << "Fish feeding ...\n"; }
  virtual void reproduce() const
    { std::cout << "Fish laying eggs ...\n"; }
  virtual void move() const
    { std::cout << "Fish swimming ...\n"; }
  virtual void speak() const {}
};

class Horse: public Mammal
{
public:
  Horse(int newAge, COLOR newColor):
    Mammal(newAge), color(newColor)
    { std::cout << "Horse constructor ...\n"; }
  virtual ~Horse()
    { std::cout << "Horse destructor ...\n"; }
  virtual void speak() const
    { std::cout << "Whinny!\n"; }
  virtual COLOR getcolor() const
    { return color; }
  virtual void sleep() const
    { std::cout << "Horse snoring ...\n"; }
  virtual void eat() const
    { std::cout << "Horse feeding ...\n"; }
  virtual void move() const
    { std::cout << "Horse running ...\n";}

protected:
  COLOR color;
};

class Dog : public Mammal
{
public:
  Dog(int newAge, COLOR newColor):
    Mammal(newAge), color(newColor)
    { std::cout << "Dog constructor ...\n"; }
  virtual ~Dog()
    { std::cout << "dog destructor ...\n"; }
  virtual void speak() const
    { std::cout << "Whoof!\n"; }
  virtual void sleep() const
    { std::cout << "Dog snoring ...\n"; }
  virtual void eat() const
    { std::cout << "Dog eating ...\n"; }
  virtual void move() const
    { std::cout << "Dog running ...\n";}
  virtual void reproduce() const 
    { std::cout << "Dogs reproducing ...\n"; }

protected:
  COLOR color;
};

int main()
{
  Animal *pAnimal = 0;
  int choice;
  bool fQuit = false;

  while(1)
  {
    std::cout << "(1) Dog (2) Horse (3) Fish (0) Quit: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
      pAnimal = new Dog(5, Brown);
      break;
    case 2:
      pAnimal = new Horse(4, Black);
      break;
    case 3:
      pAnimal = new Fish(5);
      break;
    default:
      fQuit = true;
      break;
    }
    if (fQuit)
      break;

    pAnimal->speak();
    pAnimal->eat();
    pAnimal->reproduce(); 
    pAnimal->move();
    pAnimal->sleep();
    delete pAnimal;
    std::cout << "\n";
  }
  return 0;
}
