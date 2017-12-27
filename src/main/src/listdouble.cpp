// Standard Template Library example using a class.

#include <iostream>
#include <list>
using namespace std;

// The List STL template requires overloading operators =, == and <.

// http://www.yolinux.com/TUTORIALS/LinuxTutorialC++STL.html
class AAA
{
   friend ostream &operator<<(ostream &, const AAA &);

   public:
      int x;
      int y;
      float z;

      AAA();
      AAA(const AAA &);
      ~AAA(){};
      AAA &operator=(const AAA &rhs);
      int operator==(const AAA &rhs) const;
      int operator<(const AAA &rhs) const;
};

AAA::AAA()   // Constructor
{
   x = 0;
   y = 0;
   z = 0;
}

AAA::AAA(const AAA &copyin)   // Copy constructor to handle pass by value.
{                             
   x = copyin.x;
   y = copyin.y;
   z = copyin.z;
}

ostream &operator<<(ostream &output, const AAA &aaa)
{
   output << aaa.x << ' ' << aaa.y << ' ' << aaa.z << endl;
   return output;
}

AAA& AAA::operator=(const AAA &rhs)
{
   this->x = rhs.x;
   this->y = rhs.y;
   this->z = rhs.z;
   return *this;
}

int AAA::operator==(const AAA &rhs) const
{
   if( this->x != rhs.x) return 0;
   if( this->y != rhs.y) return 0;
   if( this->z != rhs.z) return 0;
   return 1;
}

// This function is required for built-in STL list functions like sort
int AAA::operator<(const AAA &rhs) const
{
   if( this->x == rhs.x && this->y == rhs.y && this->z < rhs.z) return 1;
   if( this->x == rhs.x && this->y < rhs.y) return 1;
   if( this->x < rhs.x ) return 1;
   return 0;
}

main()
{
   list<AAA> L;
   AAA Ablob ;

   Ablob.x=7;
   Ablob.y=2;
   Ablob.z=4.2355;
   L.push_back(Ablob);  // Insert a new element at the end

   Ablob.x=5;
   L.push_back(Ablob);  // Object passed by value. Uses default member-wise
                        // copy constructor
   Ablob.z=3.2355;
   L.push_back(Ablob); 

   Ablob.x=3;
   Ablob.y=7;
   Ablob.z=7.2355;
   L.push_back(Ablob); 

   list<AAA>::iterator i;

   cout << "Print x: " << endl;
   for(i=L.begin(); i != L.end(); ++i) cout << (*i).x << " "; // print member
   cout << endl << endl;      

   cout << "Print x, y, z: " << endl;
   for(i=L.begin(); i != L.end(); ++i) cout << *i; // print with overloaded operator
   cout << endl;

   cout << "Sorted: " << endl;
   L.sort();
   for(i=L.begin(); i != L.end(); ++i) cout << *i; // print with overloaded operator
   cout << endl;

   cout << "Iterate in Reverse: " << endl;
   list<AAA>::reverse_iterator ri;
   for(ri=L.rbegin(); ri != L.rend(); ++ri) cout << *ri; // print with overloaded operator
   cout << endl;

   cout << "Remove where x=5: " << endl;
   for(i=L.begin(); i != L.end(); )       // Don't increment iterator here
       if( (*i).x == 5 ) i = L.erase(i);  // Returns iterator to the next item in the list
       else ++i;                          // Increment iterator here
   for(i=L.begin(); i != L.end(); ++i) cout << *i; // print with overloaded operator
   cout << endl;

   return 0;
}
