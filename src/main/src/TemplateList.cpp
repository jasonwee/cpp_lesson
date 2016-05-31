#include <iostream>

enum { kIsSmaller, kIsLarger, kIsSame};

class Data
{
public: 
  Data(int newVal):value(newVal) {}
  ~Data()
  {
    std::cout << "Deleting Data object with value: ";
    std::cout << value << "\n";
  }
  int compare(const Data&);
  void show() { std::cout << value << "\n"; }
private:
  int value;
};

int Data::compare(const Data& otherObject)
{
  if (value < otherObject.value)
    return kIsSmaller;
  if (value > otherObject.value)
    return kIsLarger;
  else 
    return kIsSame;
}

class Cat
{
public:
  Cat(int newAge):age(newAge) {}
  ~Cat()
  {
    std::cout << "Deleting " << age 
        << " year old Cat.\n";
  }
  int compare(const Cat&);
  void show()
  {
    std::cout << "This cat is " << age 
        << " years old\n";
  }
private:
  int age;
};

int Cat::compare(const Cat& otherCat)
{
  if (age < otherCat.age)
    return kIsSmaller;
  if (age > otherCat.age)
    return kIsLarger;
  else
    return kIsSame;
}

template <class T>
class Node
{
public:
  Node(){}
  virtual ~Node() {}
  virtual Node* insert(T* object) = 0;
  virtual void show() = 0;
private:
};

template <class T>
class InternalNode: public Node<T>
{
public:
  InternalNode(T* theObject, Node<T>* next);
  virtual ~InternalNode() { delete next; delete object; }
  virtual Node<T> * insert(T * object);
  virtual void show()
  {
    object->show();
    next->show();
  }
private:
  T* object;
  Node<T>* next;
};

template <class T>
InternalNode<T>::InternalNode(T* newObject, Node<T>* newNext):
object(newObject), next(newNext)
{
}

template <class T>
Node<T>* InternalNode<T>::insert(T* newObject)
{
  int result = object->compare(*newObject);

  switch(result)
  {
  case kIsSame:
  case kIsLarger:
    {
      InternalNode<T>* objectNode =
      new InternalNode<T>(newObject, this);
      return objectNode;
    }
  case kIsSmaller:
    next = next->insert(newObject);
    return this;
  }
  return this;
}

template <class T>
class TailNode : public Node<T>
{
public:
  TailNode() {}
  virtual ~TailNode() {}
  virtual Node<T>* insert(T * object);
  virtual void show() { }
private:
};

template <class T>
Node<T>* TailNode<T>::insert(T * object)
{
  InternalNode<T>* objectNode =
  new InternalNode<T>(object, this);
  return objectNode;
}

template <class T>
class HeadNode : public Node<T>
{
public:
  HeadNode();
  virtual ~HeadNode() { delete next; }
  virtual Node<T>* insert(T * object);
  virtual void show() { next->show(); }
private:
  Node<T> * next;
};

template <class T>
HeadNode<T>::HeadNode()
{
  next = new TailNode<T>;
}

template <class T>
Node<T> * HeadNode<T>::insert(T* object)
{
  next = next->insert(object);
  return this;
}

template <class T>
class LinkedList
{
public:
  LinkedList();
  ~LinkedList() { delete head; }
  void insert(T* object);
  void showAll() { head->show(); }
private:
  HeadNode<T> * head;
};

template <class T>
LinkedList<T>::LinkedList()
{
  head = new HeadNode<T>;
}

template <class T>
void LinkedList<T>::insert(T* pObject)
{
  head->insert(pObject);
}

void myFunction(LinkedList<Cat>& listOfCats);
void myOtherFunction(LinkedList<Data>& listOfData);

int main()
{
  LinkedList<Cat> listOfCats;
  LinkedList<Data> listOfData;

  myFunction(listOfCats);
  myOtherFunction(listOfData);

  std::cout << "\n";
  listOfCats.showAll();
  std::cout << "\n";
  listOfData.showAll();
  std::cout << "\n***********\n\n";
  return 0;
}

void myFunction(LinkedList<Cat>& listOfCats)
{
  Cat* pCat;
  int val;

  while (true)
  {
    std::cout << "\nHow old is your cat (0 to stop)? ";
    std::cin >> val;
    if (!val)
      break;
    pCat = new Cat(val);
    listOfCats.insert(pCat);
  }
}

void myOtherFunction(LinkedList<Data>& listOfData)
{
  Data* pData;
  int val;

  while (true)
  {
    std::cout << "\nWhat value (0 to stop)? ";
    std::cin >> val;
    if (!val)
      break;
    pData = new Data(val);
    listOfData.insert(pData);
  }
}
