#include <iostream>

class Shape
{
public:
  Shape() {}
  virtual ~Shape() {}
  virtual long getArea() { return -1; } // error
  virtual long getPerim() { return -1; }
  virtual void draw() {}
};

class Circle : public Shape
{
public:
  Circle (int newRadius):radius(newRadius) {}
  ~Circle() {}
  long getArea() { return 3 * radius * radius; }
  long getPerim() { return 9 * radius; }
  void draw();
private:
  int radius;
  int circumference;
};

void Circle::draw()
{
  std::cout << "Circle drawing routine here!\n";
}

class Rectangle : public Shape
{
public:
  Rectangle (int newLen, int newWidth):
    length(newLen), width(newWidth) {}
  virtual ~Rectangle() {}
  virtual long getArea() { return length * width; }
  virtual long getPerim() { return 2 * length + 2 * width; }
  virtual int getLength() { return length; }
  virtual int getWidth() { return width; }
  virtual void draw();
private:
  int width;
  int length;
};

void Rectangle::draw()
{
  for (int i = 0; i < length; i++)
  {
    for (int j = 0; j < width; j++)
      std::cout << "x ";

    std::cout << "\n";
  }
}

class Square : public Rectangle
{
public:
  Square(int len);
  Square(int len, int width);
  ~Square() {}
  long getPerim() { return 4 * getLength(); }
};

Square::Square(int newLen):
  Rectangle(newLen, newLen)
{}

Square::Square(int newLen, int newWidth):
  Rectangle(newLen, newWidth)
{
  if (getLength() != getWidth())
    std::cout << "Error, not a square ... a rectangle?\n";
}

int main()
{
  int choice;
  bool fQuit = false;
  Shape * sp;

  while (1)
  {
    std::cout << "(1) Circle (2) Rectangle (3) Square (0) Quit: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
      sp = new Circle(5);
      break;
    case 2:
      sp = new Rectangle(4, 6);
      break;
    case 3:
      sp = new Square(5);
      break;
    default:
      fQuit = true;
      break;
    }
    if (fQuit)
      break;

    sp->draw();
    std::cout << "\n";
  }
  return 0;
}
