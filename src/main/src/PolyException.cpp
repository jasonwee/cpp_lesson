#include <iostream>

const int defaultSize = 10;

 // define the exception classes
class XBoundary {};

class XSize
{
public:
  XSize(int newSize):size(newSize) {}
  ~XSize() {}
  virtual int getSize() { return size; }
  virtual void printError()
  { std::cout << "Size error. Received: "
      << size << "\n"; }
protected:
  int size;
};

class XTooBig : public XSize
{
public:
  XTooBig(int size):XSize(size) {}
  virtual void printError()
  {
    std::cout << "Too big! Received: ";
    std::cout << XSize::size << "\n";
  }
};

class XTooSmall : public XSize
{
public:
  XTooSmall(int size) : XSize(size) {}
  virtual void printError()
  {
    std::cout << "Too small! Received: ";
    std::cout << XSize::size << "\n";
  }
};

class XZero: public XTooSmall
{
public:
  XZero(int newSize):XTooSmall(newSize){}
  virtual void printError()
  {
    std::cout << "Zero Received: ";
    std::cout << XSize::size << "\n";
  } 
};

class XNegative : public XSize
{
public:
  XNegative(int size):XSize(size){}
  virtual void printError()
  {
    std::cout << "Negative! Received: ";
    std::cout << XSize::size << "\n";
  }
};

class Array
{
public:
  // constructors
  Array(int size = defaultSize);
  Array(const Array &rhs);
  ~Array() { delete [] pType; }

  // operators
  Array& operator=(const Array&);
  int& operator[](int offSet);
  const int& operator[](int offSet) const;

  // accessors
  int getSize() const { return size; }

  // friend function
  friend std::ostream& operator<< (std::ostream&, const Array&);


private:
  int *pType;
  int size;
};

Array::Array(int newSize):
size(newSize)
{
  if (newSize == 0)
    throw XZero(size);

  if (newSize < 0)
    throw XNegative(size);

  if (newSize < 10)
    throw XTooSmall(size);

  if (newSize > 30000)
    throw XTooBig(size);

  pType = new int[newSize];
  for (int i = 0; i < newSize; i++)
    pType[i] = 0;
}

int& Array::operator[] (int offset)
{
  int size = getSize();
  if (offset >= 0 && offset < size)
    return pType[offset];
  throw XBoundary();
  return pType[offset];
}

const int& Array::operator[] (int offset) const
{
  int size = getSize();
  if (offset >= 0 && offset < size)
    return pType[offset];
  throw XBoundary();
  return pType[offset];
}

int main()
{
  try
  {
    int choice;
    std::cout << "Enter the array size: ";
    std::cin >> choice;
    Array intArray(choice);
    for (int j = 0; j < 100; j++)
    {
      intArray[j] = j;
      std::cout << "intArray[" << j << "] OK ..."
          << "\n";
    }
  }
  catch (XBoundary)
  {
    std::cout << "Unable to process your input\n";
  }
  catch (XSize& exception)
  {
    exception.printError();
  }
  catch (...)
  {
    std::cout << "Something went wrong,"
        << "but I've no idea what!" << "\n";
  }
  std::cout << "Done\n";
  return 0;
}
