#include <iostream>

const int defaultSize = 10;

// define the exception class
class XBoundary
{
public:
  XBoundary() {}
  ~XBoundary() {}
private:
};

class Array
{
public:
  // constructors
  Array(int size = defaultSize);
  Array(const Array &rhs);
  ~Array() { delete[] pType; }

  // operators 
  Array& operator=(const Array&);
  int& operator[](int offSet);
  const int& operator[](int offSet) const;

  // accessors
  int getSize() const {return size; }

  // friend function
  friend std::ostream& operator<<(std::ostream&, const Array&);

private:
  int *pType;
  int size;
};

Array::Array(int newSize):
size(newSize)
{
  pType = new int[size];
  for (int i = 0; i < size; i++)
    pType[i] = 0;
}

Array& Array::operator=(const Array &rhs)
{
  if (this == &rhs)
    return *this;
  delete [] pType;
  size = rhs.getSize();
  pType = new int[size];
  for (int i = 0; i < size; i++)
    pType[i] = rhs[i];
  return *this;
}

Array::Array(const Array &rhs)
{
  size = rhs.getSize();
  pType = new int[size];
  for (int i = 0; i < size; i++)
    pType[i] = rhs[i];
}

int& Array::operator[](int offSet)
{
  int size = getSize();
  if (offSet >= 0 && offSet < size)
    return pType[offSet];
  throw XBoundary();
  return pType[offSet];
}

const int& Array::operator[](int offSet) const
{
  int size = getSize();
  if (offSet >= 0 && offSet < size)
    return pType[offSet];
  throw XBoundary();
  return pType[offSet];
}

std::ostream& operator<<(std::ostream& output, 
                         const Array& array)
{
  for (int i = 0; i < array.getSize(); i++)
    output << "[" << i << "] " << array[i] << "\n";
  return output;
}

int main()
{
  Array intArray(20);
  try
  {
    for (int j = 0; j < 100; j++)
    {
      intArray[j] = j;
      std::cout << "intArray[" << j 
          << "] OK ..." << "\n";
    }
  }
  catch (XBoundary)
  {
    std::cout << "Unable to process your input\n";
  }
  std::cout << "Done\n";
  return 0;
}
