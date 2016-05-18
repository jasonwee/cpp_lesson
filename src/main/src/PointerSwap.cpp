#include <iostream>

void swap(int *x, int *y);

int main()
{
  int x = 5, y = 10;

  std::cout << "Main. Before swap, x: " << x
            << " y: " << y << "\n";
  swap(&x, &y);
  std::cout << "Main. After swap, x: " << x
            << " y: " << y << "\n";
  return 0;
}

void swap (int *px, int *py)
{
  int temp;
 
  std::cout << "Swap. Before swap, *px: " << *px
            << " *py: " << *py << "\n";

  temp = *px;
  *px = *py;
  *py = temp;

  std::cout << "Swap. After swap, *px: " << *px
            << " *py: "  << *py << "\n";
}
