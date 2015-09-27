#include "lecture4.h"
#include <iostream>

using namespace std;

lecture4::lecture4()
{
    //ctor
}

lecture4::~lecture4()
{
    //dtor
}

void lecture4::learnArray() {
    // declare array example 1
    int array1[2];

    // declare and initialized array.
    int array2[5] = {1,2,2,9,7};

    // access array
    cout << array2[0] << endl; // access 1st element in the array2.

    for (int x = 0 ; x < 5; x++) {
        cout << array2[x] << endl;
    }

    // arrays are passed by references
    int arr[] = {1,2,3,4,5,6,7};
    cout << "Sum: " << sum(arr, 7) << endl;

    // multi dimensional arrays  2 rows 4 columns.
    /*   6 0 9 6
         2 0 9 8
    */
    int twoDimArray[2][4];
    twoDimArray[0][0] = 6;
    twoDimArray[0][1] = 0;
    twoDimArray[0][2] = 9;
    twoDimArray[0][3] = 6;
    twoDimArray[1][0] = 2;
    twoDimArray[2][1] = 0;
    twoDimArray[3][2] = 9;
    twoDimArray[4][3] = 8;

    // another multi dimensional array declaration.
    int twoDimArray1[2][4] = { { 6, 0, 9, 6 } , { 2, 0, 1, 1 } };

    // \0 is null character.
    char helloworld[] = { 'H', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '!', '\0' };

    // if you do like this, compiler automatically insert for you.
    char helloWord[] = "Hello, World!";

    // what are the libraries available and what are they for? read below
    // http://www.cplusplus.com/reference/



}

int lecture4::sum(const int array[], const int length) {
    long sum = 0;

    for (int i = 0; i < length; sum+= array[i++]);

    return sum;
}
