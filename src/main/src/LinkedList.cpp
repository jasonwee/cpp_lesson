/* Demonstrates an object-oriented approach to
 * linked lists. The list delegats to the node.
 * The node is an abstract data type. Three types of
 * nodes are used, head nodes, tail nodes and internal
 * nodes. Only the internal nodes ohld data.
 *
 * The Data class is created to serve as an object to
 * hold in the linkedin list.
 */
#include <iostream>

enum { kIsSmaller, kIsLarger, kIsSame } ;

// Data class to put into the linked list
// Any clas in this linked list must support two
// functions: show (displays the value) and compare
// (returns relative position)
class Data
{
public:
  Data(int newVal):value(newVal) {}
  ~Data() {}
  int compare(const Data&);
  void show() { std::cout << value << "\n"; }
private:
  int value;
};

// compare is used to decide where in the list
// a particular object belongs.
int Data::compare(const Data& otherData)
{
  if (value < otherData.value)
    return kIsSmaller;
  if (value > otherData.value)
    return kIsLarger;
  else
    return kIsSame;
}

// forward declarations
class Node;
class HeadNode;
class TailNode;
class InternalNode;

// ADT representing the node object in the list.
// Every derived class must override insert and show.
class Node
{
public:
  Node() {}
  virtual ~Node() {}
  virtual Node* insert(Data* data) = 0;
  virtual void show() = 0;
private:
};

//  This is the node that holds the actual object.
//  In this case the object is of type Data.
//  We'll see how to make this more general when
//  we cover templates.
class InternalNode : public Node
{
public:
  InternalNode(Data* data, Node* next);
  virtual ~InternalNode() { delete next; delete data; }
  virtual Node* insert(Data* data);
  virtual void show()
    { data->show(); next->show(); } // delegate!

private:
  Data* data; // the data itself
  Node* next; // points to next node in the linked list
};

// All the constructor does it to initialize
InternalNode::InternalNode(Data* newData, Node* newNext):
data(newData), next(newNext)
{
}

// The meat of the list.
// When you put a new object into the list
// it is passed to the node which figures out
// where it goes and inserts it into the list
Node* InternalNode::insert(Data* otherData)
{
  // is the new guy bigger or smaller than me?
  int result = data->compare(*otherData);

  switch(result)
  {
  //by convention if it is the same as me it comes first
  case kIsSame:   // fall through
  case kIsLarger: // new data comes before me
    {
      InternalNode* dataNode = 
        new InternalNode(otherData, this);
      return dataNode;
    }

    // it is bigger than I am so pass it on the next
    // node and let IT handle it.
  case kIsSmaller:
    next = next->insert(otherData);
    return this;
  }
  return this; // appease the compiler
}

// tail node is just a sentinel
class TailNode : public Node
{
public:
  TailNode() {}
  virtual ~TailNode() {}
  virtual Node* insert(Data* data);
  virtual void show() {}
private:
};

// If data comes to me, it must be inserted before me
// as I am the tail and NOTHING comes after me
Node* TailNode::insert(Data* data)
{
  InternalNode* dataNode = new InternalNode(data, this);
  return dataNode;
}

// Head node has no data, it just points
// to the very beginning of the list
class HeadNode : public Node
{
public:
  HeadNode();
  virtual ~HeadNode() { delete next; }
  virtual Node* insert(Data* data);
  virtual void show() { next->show(); }
private:
  Node* next;
};

// As soon as the head is created
// it creates the tail
HeadNode::HeadNode()
{
  next = new TailNode;
}

// Nothing comes before the head so 
// pass the data on to the next node
Node* HeadNode::insert(Data* data)
{
  next = next->insert(data);
  return this;
}

// I get all the credit and do none of the work
class LinkedList
{
public:
  LinkedList();
  ~LinkedList() { delete head; }
  void insert(Data* data);
  void showAll() { head->show(); }
private:
  HeadNode* head;
};

// At birth, i create the head node
// It creates the tail node
// So an empty list points to the head which
// pionts to the tail and has nothing between
LinkedList::LinkedList()
{
  head = new HeadNode;
}

// Delegate, delegate, delegate
void LinkedList::insert(Data* pData)
{
  head->insert(pData);
}

// test driver program
int main()
{
  Data* pData;
  int val;
  LinkedList ll;

  // ask the user to produce some values
  // put them in the list
  while (true)
  {
    std::cout << "What value (0 to stop)? ";
    std::cin >> val;
    if (!val)
      break;
    pData = new Data(val);
    ll.insert(pData);
  }

  // now walk the list and show the data
  ll.showAll();
  return 0;   // ll falls out of scope and is destroyed!
}
