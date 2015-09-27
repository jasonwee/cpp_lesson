#include "lecture6.h"
#include <iostream>
#include <MITStudent.h>

using namespace std;

lecture6::lecture6()
{
    double xStart = 1.2;
    double xEnd = 2.0;
    double yStart = 0.4;
    double yEnd = 1.6;


    printVector(xStart, xEnd, yStart, yEnd);

    offsetVector(xStart, xEnd, yStart, yEnd, 1.0, 1.5);
    printVector(xStart, xEnd, yStart, yEnd);

    /*
    MITStudent student1;
    MITStudent student2;

    student1.name = "Jason";
    student1.studentID = 1234567;

    student2.name = "John";
    student2.studentID = 1234568;

    cout << "student1 name is " << student1.name << endl;
    cout << "student1 id is " << student1.studentID << endl;
    cout << "student2 name is " << student2.name << endl;
    cout << "student2 id is " << student2.studentID << endl;
    */


}

lecture6::~lecture6()
{
    //dtor
}


void lecture6::printVector(double x0, double x1, double y0, double y1) {
    cout << "(" << x0 << "," << y0 << ") -> ("<< x1 << "," << y1 << ")" << endl;
}

void lecture6::offsetVector(double &x0, double &x1, double &y0, double &y1, double offsetX, double offsetY) {
    x0 += offsetX;
    x1 += offsetX;
    y0 += offsetY;
    y1 += offsetY;
}
