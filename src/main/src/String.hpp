#include <iostream>
#include <string.h>

class String
{
public:
  // constructors
  String();
  String(const char *const);
  String(const String&);
  ~String();

  // overloaded operators
  char& operator[](int offset);
  char operator[](int offset) const;
  String operator+(const String&);
  void operator+=(const String*);
  String& operator= (const String &);

  // general accessors
  int getLen() const { return len; }
  const char* getString() const { return value; }
  // static int constructorCount;

private:
  String(int); // private constructor
  char* value;
  int len;
};

// default constructor creates string of 0 bytes
String::String()
{
  value = new char[1];
  value[0] = '\0';
  len = 0;
  // std::cout << "\tDefault string constructor\n";
  // constructorCount++;
}

// private (helper) constructor, used only by
// class functions for creating a new string of
// required size. Null filled.
String::String(int len)
{
  value = new char[len +1];
  int i;
  for (i = 0; i < len; i++)
    value[i] = '\0';
  len = len;
  // std::cout << "\tString(int) constructor\n";
  // constructorCount++;
}

String::String(const char* const cString)
{
  len = strlen(cString);
  value = new char[len + 1];
  int i ;
  for (i=0; i < len; i++)
    value[i] = cString[i];
  value[len] = '\0';
  // std::cout << "\tString(char*) constructor\n";
  // constructorCount++;
}

String::String(const String& rhs)
{
  len = rhs.getLen();
  value = new char[len + 1];
  int i;
  for (i=0; i < len; i++)
    value[i] = rhs[i];
  value[len] = '\0';
  // std::cout << "\tString(String&) constructor\n";
  // constructorCount++;
}

String::~String()
{
  delete[] value;
  len = 0;
  // std::cout << "\tString destructor\n";
}

// operator equals, frees existing memroy
// then copies string and size
String& String::operator=(const String &rhs)
{
  if (this == &rhs)
    return *this;
  delete [] value;
  len = rhs.getLen();
  value = new char[len + 1];
  int i;
  for (i=0; i < len; i++)
    value[i] = rhs[i];
  value[len] = '\0';
  return *this;
  // std::cout << "\tString operator=\n";
}

// non constant offset operator, returns
// referene to character so it can be
// changed!
char& String::operator[](int offset)
{
  if (offset > len)
    return value[len -1];
  else
    return value[offset];
}

// constant offset operator for use
// on const objects (see copy constructor!)
char String::operator[](int offset) const
{
  if (offset > len)
    return value[len-1];
  else
    return value[offset];
}

// creats a new string by adding current
// string to rhs
String String::operator+(const String& rhs)
{
  int totalLen = len + rhs.getLen();
  int i, j;
  String temp(totalLen);
  for (i=0; i < len; i++)
    temp[i] = value[i];
  for (j=0; j < rhs.getLen(); j++, i++)
    temp[i] = rhs[j];
  temp[totalLen] = '\0';
  return temp;
}

// changes current string, returns nothing
void String::operator+=(const String& rhs)
{
  int rhsLen = rhs.getLen();
  int totalLen = len + rhsLen;
  int i, j;
  String temp(totalLen);
  for (i=0; i < len; i++)
    temp[i] = value[i];
  for (j=0; j < rhs.getLen(); j++, i++)
    temp[i] = rhs[i-len];
  temp[totalLen] = '\0';
  *this = temp;
}

// int String::constructorCount = 0;
