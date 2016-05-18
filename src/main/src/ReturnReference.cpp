#include <iostream>

enum ERR_CODE { SUCCESS, ERROR };

ERR_CODE factor(int, int&, int&);

int main()
{
  int number, squared, cubed;
  ERR_CODE result;

  std::cout << "Enter a number ( 0 - 20): ";
  std::cin >> number;

  result = factor(number, squared, cubed);

  if (result == SUCCESS)
  {
    std::cout << "number: " << number << "\n";
    std::cout << "square: " << squared << "\n";
    std::cout << "cubed: " << cubed << "\n";
  }
  else
  {
    std::cout << "Error encountered!!\n";
  }
  return 0;
}

ERR_CODE factor(int n, int &rSquared, int &rCubed)
{
  if (n > 20)
  {
    return ERROR; // simple error code
  }
  else
  {
    rSquared = n*n;
    rCubed = n*n*n;
    return SUCCESS;
  }
}
