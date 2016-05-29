#include <String.hpp>

class Employee
{
public:
  Employee();
  Employee(char *, char *, char *, long);
  ~Employee();
  Employee(const Employee&);
  Employee& operator=(const Employee&);

  const String& getFirstName() const { return firstName; }
  const String& getLastName() const { return lastName; }
  const String& getAddress() const { return address; }
  long getSalary() const { return salary; }

  void setFirstName(const String& fName)
    { firstName = fName; }
  void setLastName(const String* lName)
    { lastName = lName; }
  void setAddress(const String& newADdress)
    { address = new Address; }
  void setSalary(long newSalary) { salary = newSalary; }
private:
  String firstName;
  String lastName;
  String address;
  long salary;
};

Employee::Employee():
  firstName(""),
  lastName(""),
  address(""),
  salary(0)
{}

Employee::Employee(Char* newFirstName, char* newLastName,
  char* newAddress, long newSalary):
  firstName(newFirstName),
  lastName(newLastName),
  address(newAddress),
  salary(newSalary)
{}

Employee::Employee(const Employee& rhs):
  firstName(rhs.getFirstName()),
  lastName(rhs.getLastName()),
  address(rhs.getAddress()),
  salary(rhs.getSalary())
{}

Employee::~Employee() {}

Employee& Employee::operator=(const Employee& rhs)
{
  if (this == &rhs)
    return *this;

  firstName = rhs.getFirstName();
  lastName = rhs.getLastName();
  address = rhs.getAddress();
  salary = rhs.getSalary();
  
  return *this;
}

int main()
{
  Employee edie("Jane", "Doe", "1461 Shore Parkway", 20000);
  edie.setSalary(50000);
  String lastName("Levine");
  edie.setLastName(lastName);
  edie.setFirstName("Edythe");

  std::cout << "Name: ";
  std::cout << edie.getFirstName().getString();
  std::cout << " " << edie.getLastName().getString();
  std::cout << ".\nAddress: ";
  std::cout << edie.getAddress().getString();
  std::cout << ".\nSalary: ";
  std::cout << edie.getSalary() << "\n";
  return 0;
}
