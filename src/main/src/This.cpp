#include <iostream>

class Rectangle
{
public:
  Rectangle();
  ~Rectangle();

  void SetLength(int length) { this->itsLength = length; }
  int GetLength() const { return this->itsLength; }
  void SetWidth(int width) { itsWidth = width; }
  int GetWidth() const { return itsWidth; }

private:
  int itsLength;
  int itsWidth;
};

Rectangle::Rectangle() {
  itsWidth = 5;
  itsLength = 10;
}

Rectangle::~Rectangle() {

}

int main() {
  Rectangle theRect;
  std::cout << "theRect is " << theRect.GetLength() << " feet long.\n";

  std::cout << " theRect is " << theRect.GetWidth() << " feet wide.\n";

  theRect.SetLength(20);
  theRect.SetWidth(10);
  std::cout << "theRect is " << theRect.GetLength() << " feet long.\n";
  std::cout << "theRect is " << theRect.GetWidth() << " feet wide.\n";

  return 0;
}
