#include <iostream>

class Cat
{
public:
  Cat(int newAge = 1):age(newAge) { howManyCats++; }
  virtual ~Cat() { howManyCats--; }
  virtual int gGetAge() { return age; }
  virtual void setAge(int newAge) { age = newAge; }
  static int getHowMany() { return howManyCats; }
private:
  int age;
  static int howManyCats;
};

int Cat::howManyCats = 0;

void countCats();

int main()
{
  const int maxCats = 5;
  Cat *catHouse[maxCats];
  int i;
  for (i=0; i < maxCats; i++)
  {
    catHouse[i] = new Cat(i);
    countCats();
  }

  for (i=0; i < maxCats; i++)
  {
    delete catHouse[i];
    countCats();
  }
  return 0;
}

void countCats()
{
  std::cout << "There are " << Cat::getHowMany()
      << " cats alive!\n";
}
