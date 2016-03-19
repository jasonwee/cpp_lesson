#include <iostream>
#include <lecture4.h>
#include <lecture5.h>
#include <lecture6.h>
#include <lecture9.h>
#include "Triangle.h"
#include "Rectangle.h"
#include "Integer.h"
#include "Box.h"

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
    /*
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
    */

    // TODO, this canot compile, why?
    //lecture9 <int> lec9;
    //lec9.setValue(3);
    //cout << lec9.getX() << endl;
    //lec9.setValue(1);
    //cout << lec9.getX() << endl;


    //cout << "Hello world!" << endl;
    //return 0;

    /*
    Box box1;  // declare box1 of type box
    Box box2;  // declare box2 of type box
    double volume = 0.0; // store the volume of a box here

    // bot 1 specification
    box1.height = 5.0;
    box1.length = 6.0;
    box1.breadth = 7.0;

    // box 2 specification
    box2.height = 10.0;
    box2.length = 12.0;
    box2.breadth = 13.0;

    // volume of box 1
    volume = box1.height * box1.length * box1.breadth;
    cout << "Volume of Box 1: " << volume <<endl;

    // volume of box2
    volume = box2.height * box2.length * box2.breadth;
    cout << "volume of box2 : " << volume << endl;
    */

    struct Employee {
        short id;
        int age;
        double wage;
    };

    Employee jason;
    Employee chloe;

    jason.id = 123;
    jason.age = 34;
    jason.wage = 456.78;

    chloe.id = 124;
    chloe.age = 34;
    chloe.wage = 789.91;

    int totalAge = jason.age + chloe.age;

    if (jason.wage > chloe.wage)
        cout << "jason make more than chloe\n";
    else if (jason.wage < chloe.wage)
        cout << "jason make less than chloe\n";
    else
        cout << "jason and frank make the same amount\n";

    // jason got a promotion
    jason.wage += 2.50;

    // today is chloe birthday
    ++chloe.age;

    // another way of initializing
    Employee oli = {125, 35, 987.12};

    Employee alec = {126, 33}; // alec.wage = 0.0 default initializaiton.

    // initalizing in c++ 11
    //Employee oli { 125, 35, 987.12};
    //Employee alec {126, 33};


    return 0;
}

