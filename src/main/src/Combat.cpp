#include <iostream>

int main()
{
  // define character values
  auto strength;
  auto accuracy;
  auto dexterity;

  // define constants
  const auto maximum = 50;

  // get user input
  std::cout << "\nEnter strength (1-100): ";
  std::cin >> strength;

  std::cout << "\nEnter accuracy (1-50): ";
  std::cin >> accuracy;
 
  std::cout << "\nEnter dexterity (1-50): ";
  std::cin >> dexterity;

  // calculate character combat stats
  auto attack = strength * (accuracy / maximum);
  auto damage = strength * (dexterity / maximum);

  std::cout << "\nAttack rating: " << attack << "\n";
  std::cout << "Damage rating: " << damage << "\n";
}
