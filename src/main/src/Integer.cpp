#include "Integer.h"
#include <iostream>

using namespace std;

// default constructor
Integer::Integer() : val(0)
{
    //ctor
}


Integer::Integer(int v) : val(v)
{
    //ctor
}

Integer::~Integer()
{
    //dtor
}

void Integer::printV() {
    cout << this->val << endl;
}
