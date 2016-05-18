#include <iostream>

class SimpleCat
{
public:
  SimpleCat();             // constructor
  SimpleCat(SimpleCat&);   // copy constructor
  ~SimpleCat();            // destructor
};

SimpleCat::SimpleCat()
{
  std::cout << "Simple Cat Constructor ...\n";
}

SimpleCat::SimpleCat(SimpleCat&)
{
  std::cout << "Simple Cat Copy Constructor ...\n";
}

SimpleCat::~SimpleCat()
{
  std::cout << "Simple Cat Destructor ...\n";
}

SimpleCat FunctionOne(SimpleCat theCat);
SimpleCat* FunctionTwo(SimpleCat *theCat);

int main() 
{
  std::cout << "Making a cat ...\n";
  SimpleCat Frisky;
  std::cout << "Calling FunctionOne ...\n";
  FunctionOne(Frisky);
  std::cout << "Calling FunctionTwo ...\n";
  FunctionTwo(&Frisky);
  return 0;
}

// FunctionOne, passes by value
SimpleCat FunctionOne(SimpleCat theCat)
{
  std::cout << "Function One. Returning ...\n";
  return theCat;
}

// functionTwo, passes by reference
SimpleCat* FunctionTwo(SimpleCat *theCat)
{
  std::cout << "Function Two. Returning ...\n";
  return theCat;
}
