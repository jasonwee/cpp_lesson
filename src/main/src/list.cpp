#include <iostream>
#include <list>
using namespace std;

// Simple example uses type int

//http://www.yolinux.com/TUTORIALS/LinuxTutorialC++STL.html
main() {

 list<int> L;
   L.push_back(0);              // Insert a new element at the end
   L.push_front(0);             // Insert a new element at the beginning
   L.insert(++L.begin(),2);     // Insert "2" before position of first argument
                                // (Place before second argument)
   L.push_back(5);
   L.push_back(6);

   list<int>::iterator i;

   for(i=L.begin(); i != L.end(); ++i) cout << *i << " ";
   cout << endl;
   return 0;

}
