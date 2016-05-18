#include <iostream>

void swap(int x, int y);

int main() 
{
  int x = 5, y = 10;

  std::cout << "Main. Before swap, x: " << x 
            << " y: " << y << "\n";
  swap(x,y);
  std::cout << "Main. After swap, x: " << x
            << " y: " << y << "\n";
  return 0;
}

void swap(int x, int y)
{
  int temp;

  std::cout << "Swap. Before swap, x: " << x
            << " y: " << y << "\n";

  temp = x;
  x = y;
  y = temp;
 
  std::cout << "Swap. After swap, x: " << x
            << " y: "  << y << "\n";

}
