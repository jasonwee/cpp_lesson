#include <iostream>
#include <lecture4.h>
#include <lecture5.h>
#include <lecture6.h>
#include "Triangle.h"
#include "Rectangle.h"

using namespace std;

int main()
{
    //lecture4 lec4;
    //lec4.learnArray();

    //lecture5 lec5;
    //lec5.learnPointer();

    //lecture6 lec6;

    // lesson 7
    Rectangle rect;
    Triangle tria;
    rect.setValue(4,5);
    tria.setValue(4,5);

    cout << rect.area() << '\n';
    cout << tria.area() << '\n';


    cout << "Hello world!" << endl;
    return 0;
}

