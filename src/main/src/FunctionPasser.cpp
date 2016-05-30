#include <iostream>

void square(int&, int&);
void cube(int&, int&);
void swap(int&, int&);
void getVals(int&, int&);
void printVals(void (*)(int&, int&), int&, int&);

int main()
{
  int valOne = 1, valTwo = 2;
  int choice;
  bool fQuit = false;

  void (*pFunc)(int&, int&);
  
  while (fQuit == false)
  {
    std::cout << "(0) Quit (1) Change Values "
        << "(2) Square (3) Cube (4) Swap: ";
    std::cin >> choice;
    switch (choice)
    {
    case 1:
      pFunc = getVals;
      break;
    case 2:
      pFunc = square;
      break;
    case 3:
      pFunc = cube;
      break;
    case 4:
      pFunc = swap;
      break;
    default:
      fQuit = true;
      break;
    }
    if (fQuit == true)
      break;
    printVals(pFunc, valOne, valTwo);
  }

  return 0;
}

void printVals(void (*pFunc)(int&, int&), int& x, int& y)
{
  std::cout << "x: " << x << " y: " << y << "\n";
  pFunc(x, y);
  std::cout << " x: " << x << " y : " << y << "\n";
}

void square(int &rX, int &rY)
{
  rX *= rX;
  rY *= rY;
}

void cube(int &rX, int &rY)
{
  int tmp;
  
  tmp = rX;
  rX *= rX;
  rX = rX * tmp;

  tmp = rY;
  rY *= rY;
  rY = rY * tmp;
}

void swap(int &rX, int &rY)
{
  int temp;
  temp = rX;
  rX = rY;
  rY = temp;
}

void getVals(int &rValOne, int &rValTwo)
{
  std::cout << "New value for valOne: ";
  std::cin >> rValOne;
  std::cout << "New value for valTwo: ";
  std::cin >> rValTwo;
}
