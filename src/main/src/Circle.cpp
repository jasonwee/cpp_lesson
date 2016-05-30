#include <iostream>

// get an approximate value of PI
constexpr double getPi() {
  return (double) 22 / 7;
}

int main()
{
  float radius;

  std::cout << "Enter the radius of the circle: ";
  std::cin >> radius;

  // the area equals PI * the radius squared
  double area = getPi() * (radius * radius);

  std::cout << "\nCircle's area: " << area << "\n";

  return 0;
}
