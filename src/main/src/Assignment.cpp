#include <iostream>

int main()
{
  int intOne;
  int &rSomeRef = intOne;

  intOne = 5;
  std::cout << "intOne:\t" << intOne << "\n";
  std::cout << "rSomeRef:\t" << rSomeRef << "\n";
  std::cout << "&intOne:\t" << &intOne << "\n";
  std::cout << "&rSomeRef:\t" << &rSomeRef << "\n";

  int intTwo = 8;
  rSomeRef = intTwo; // not what you think!
  std::cout << "\nintOne:\t" << intOne << "\n";
  std::cout << "intTwo:\t" << intTwo << "\n";
  std::cout << "rSomeRef:\t" << rSomeRef << "\n";
  std::cout << "&intOne:\t" << &intOne << "\n";
  std::cout << "&intTwo:\t" << &intTwo << "\n";
  std::cout << "&rSomeRef:\t" << &rSomeRef << "\n";
  return 0;
}
