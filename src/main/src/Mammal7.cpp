#include <iostream>

class Mammal
{
public:
  void move() const {std::cout << "Mammal moves one step\n"; }
  void move(int distance) const
       { std::cout << "Mammal moves " << distance << " steps \n"; }
protected:
  int age;
  int weight;
};

class Dog : public Mammal
{
public:
  void move() const;
}; 

void Dog::move() const
{
  std::cout << "Dog moves ...\n";
  Mammal::move(3);
}

int main()
{
  Mammal bigAnimal;
  Dog fido;
  bigAnimal.move(2);
  fido.Mammal::move(10);
  return 0;
}
