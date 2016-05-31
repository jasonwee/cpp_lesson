/* Demonstrates an object-oriented approach to parameterized
 * linked lists. The list delegates to the node.
 * The node is an abstract Object type. Three types of
 * nodes are used, head nodes, tail nodes and internal
 * nodes. Only the internal nodes hold Object.
 *
 * The Object class is created to serve as an object to
 * hold in the linked list.
 *
 */
#include <iostream>

enum { kIsSmaller, kIsLarger, kIsSame};

// Object class to put into the linked list
// Any class in this linked lst must support two member
// functions: show (displays the value) and 
// compare (returns relative position)
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

// compare is used to decide where in the list
// a particular object belongs.
int Data::compare(const Data& otherObject)
{
  if (value < otherObject.value)
    return kIsSmaller;
  if (value > otherObject.value)
    return kIsLarger;
  else 
    return kIsSame;
}

// Another class to put into the linked list
// Again, every class in this linked
// list must support two member functions:
// Show (displays the value) and
// Compare (returns relative position)
class Cat
{
public:
  Cat(int newAge):age(newAge) {}
  ~Cat()
  {
    std::cout << "Deleting ";
    std::cout << age << " year old Cat.\n";
  }
  int compare(const Cat&);
  void show()
  {
    std::cout << "This cat is ";
    std::cout << age << " years old\n";
  }
private:
  int age;
};

// compare is used to decide where in the list
// a particular object belongs.
int Cat::compare(const Cat& otherCat)
{
  if (age < otherCat.age)
    return kIsSmaller;
  if (age > otherCat.age)
    return kIsLarger;
  else
    return kIsSame;
}

// ADT representing the node object in the list
// Every derived class must override insert and show
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
  InternalNode(T* object, Node<T>* next);
  ~InternalNode() { delete next; delete object; }
  virtual Node<T> * insert(T * object);
  virtual void show()
  {
    object->show();
    next->show();
  } // delegate!
private:
  T* object; // the Object itself
  Node<T>* next; // points to next node in the linked list
};

// All the constructor does is initialize
template <class T>
InternalNode<T>::InternalNode(T* newObject, Node<T>* newNext):
object(newObject), next(newNext)
{
}

// the meat of the list
// When you put a new object into the list
// it is passed to the node which figures out
// where it goes and inserts it into the list
template <class T>
Node<T>* InternalNode<T>::insert(T* newObject)
{
  // is the new guy bigger or smaller than me?
  int result = object->compare(*newObject);

  switch(result)
  {
  // by convention if it is the same as me it comes first
  case kIsSame:     // fall through
  case kIsLarger:   // new object comes before me
    {
      InternalNode<T>* objectNode =
      new InternalNode<T>(newObject, this);
      return objectNode;
    }
  // it is bigger than I am so pass it on to the next
  // node and let HIM handle it.
  case kIsSmaller:
    next = next->insert(newObject);
    return this;
  }
  return this;  //appease MSC
}

// Tail node is just a sentinel
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

// If object comes to me, it must be inserted before me
// as I am the tail and NOTHING comes after me
template <class T>
Node<T>* TailNode<T>::insert(T * object)
{
  InternalNode<T>* objectNode =
  new InternalNode<T>(object, this);
  return objectNode;
}

// Head node has no Object, it just points
// to the very beginning of the list
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

// As soon as the head is created
// it creates the tail
template <class T>
HeadNode<T>::HeadNode()
{
  next = new TailNode<T>;
}

// Nothing comes before the head so just
// pass the Object on to the next node
template <class T>
Node<T> * HeadNode<T>::insert(T* object)
{
  next = next->insert(object);
  return this;
}

// I get all the credit and do none of the work
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

// At birth, I create the head node
// It creates the tail node
// So an empty list points to the head which
// points to the tail and has nothing between
template <class T>
LinkedList<T>::LinkedList()
{
  head = new HeadNode<T>;
}

// Delegate, delegate, delegate
template <class T>
void LinkedList<T>::insert(T* pObject)
{
  head->insert(pObject);
}

// test driver program
int main()
{
  Cat* pCat;
  Data* pData;
  int val;
  LinkedList<Cat> listOfCats;
  LinkedList<Data> listOfData;

  // ask the user to produce some values
  // put them in the list
  while (true)
  {
    std::cout << "What value (0 to stop)? ";
    std::cin >> val;

    if (!val)
      break;
    pCat = new Cat(val);
    pData = new Data(val);
    listOfCats.insert(pCat);
    listOfData.insert(pData);
  }

  // now walk the list and show the Object
  std::cout << "\n";
  listOfCats.showAll();
  std::cout << "\n";
  listOfData.showAll();
  std::cout << "\n***********\n\n";
  return 0;  // The lists fall out of scope and are destroyed!
}
