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
