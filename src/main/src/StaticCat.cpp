#include <iostream>

class Cat
{
public:
  Cat(int newAge = 1):age(newAge) { howManyCats++; }
  virtual ~Cat() { howManyCats--; }
  virtual int getAge() { return age; }
  virtual void setAge(int newAge) { age = newAge; }
  static int howManyCats;

private:
  int age;
};

int Cat::howManyCats = 0;

int main()
{
  const int maxCats = 5;
  Cat *catHouse[maxCats];
  int i;
  for (i=0; i < maxCats; i++)
    catHouse[i] = new Cat(i);

  for (i=0; i < maxCats; i++)
  {
    std::cout << "There are ";
    std::cout << Cat::howManyCats;
    std::cout << " cats left!\n";
    std::cout << "Deleting the one which is ";
    std::cout << " years old\n";
    delete catHouse[i];
    catHouse[i] = 0;
  }
  return 0;
}
