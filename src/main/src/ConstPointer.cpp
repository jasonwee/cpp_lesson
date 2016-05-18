#include <iostream>

class Rectangle {

public:
  Rectangle();
  ~Rectangle();
  void SetLength(int length) { itsLength = length; }
  int GetLength() const { return itsLength; }

  void SetWidth(int width) { itsWidth = width; }
  int GetWidth() const { return itsWidth; }

private:
  int itsLength;
  int itsWidth;
};

Rectangle::Rectangle():
itsWidth(5), 
itsLength(10)
{}

Rectangle::~Rectangle()
{}

int main() 
{
  Rectangle* pRect = new Rectangle;
  const Rectangle *pConstRect = new Rectangle;
  Rectangle* const pConstPtr = new Rectangle;

  std::cout << "pRect width: " 
            << pRect->GetWidth() << " feet\n";
  std::cout << "pConstRect width: "
            << pConstRect->GetWidth() << " feet\n";
  std::cout << "pConstPtr width: "
            << pConstPtr->GetWidth() << " feet\n";

  pRect->SetWidth(10);
  //pConstRect->SetWidth(10);
  pConstPtr->SetWidth(10);

  std::cout << "pRect width: "
            << pRect->GetWidth() << " feet\n";
  std::cout << "pConstRect width: "
            << pConstRect->GetWidth() << " feet\n";
  std::cout << "pConstPtr width: "
            << pConstPtr->GetWidth() << " feet\n";
  return 0;
}
