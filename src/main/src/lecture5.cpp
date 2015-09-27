#include "lecture5.h"
#include <iostream>

using namespace std;

lecture5::lecture5()
{
    //ctor
}

lecture5::~lecture5()
{
    //dtor
}

void lecture5::learnPointer() {
    int x = 10;

    // declare a int pointer which point to the address of x.
    int *ptr = &x;

    // to show the value pointed to the address, we need to *dereference* it.
    cout << *ptr << endl;

    squareByPtr(ptr);
    cout << "x is now " << *ptr << endl;

    squareByPtr(&x);
    cout << "x is now " << *ptr << endl;


    // declares a changeable pointer to a constant integer.
    const int *ptr1;

    // changeable int but not the pointer.
    int * const ptr2 = 0;

    // no change int , no change pointer.
    const int * const ptr3 = NULL;


    int y;
    int &z = y; // Makes z a reference to , or alias of , y

    y = 5;
    cout << "y is " << y << endl;
    cout << "z is " << z << endl;

    y = 6;
    cout << "y is " << y << endl;
    cout << "z is " << z << endl;

    long arr[] = {6, 0 , 9 , 12};
    long *ptr4 = arr;
    ptr4++;
    long *ptr5 = arr + 3;

    cout << *ptr4 << endl;
    cout << *ptr5 << endl;

    long arrayElement =  *(arr+2);

    cout << "arr " << arrayElement << endl;

    char courseName1[] = {'a', 'b', 'c', '\0'};  // you can change this
    char *courseName2 = "abc";   // you cannot change the string

    courseName1[0] = 'e';
    cout << "courseName1 " << *courseName1 << endl;

    // following are wrong.
    // *courseName2 = 'e';  //
    //cout << "courseName2 " << courseName2 << endl;


}

void lecture5::squareByPtr(int *numPtr) {
    *numPtr = *numPtr * *numPtr;
}
