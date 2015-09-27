#include <iostream>
#include <lecture4.h>
#include <lecture5.h>
#include <lecture6.h>
#include "Triangle.h"
#include "Rectangle.h"
#include "Integer.h"

using namespace std;

int * getPtrToFive() {
    int * x = new int;
    *x = 5;
    return x;
}

int main()
{
    //lecture4 lec4;
    //lec4.learnArray();

    //lecture5 lec5;
    //lec5.learnPointer();

    //lecture6 lec6;

    // lesson 7
    /*
    Rectangle rect;
    Triangle tria;
    rect.setValue(4,5);
    tria.setValue(4,5);

    cout << rect.area() << '\n';
    cout << tria.area() << '\n';
    */

    // lesson 8
    Integer int1(12);
    int1.printV();

    Integer int2;
    int2.printV();

    // new : alocate memory automatically.
    int *zz = new int;

    // free the memory
    delete(zz);

    int *z1 = getPtrToFive();
    cout << *z1 << endl;
    // MUST DELETE here or memory leak will happen.
    // use delete for new operator and no need delete twice.
    delete z1;

    int numItems;
    cout << "how many items?";
    cin >> numItems;
    int arr[numItems]; // this is wrong.

    int *arr1 = new int[numItems]; // this is correct.
    delete[] arr1;





    cout << "Hello world!" << endl;
    return 0;
}

