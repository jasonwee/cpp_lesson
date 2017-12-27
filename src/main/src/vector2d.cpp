#include <iostream>
#include <vector>

using namespace std;

// http://www.yolinux.com/TUTORIALS/LinuxTutorialC++STL.html
main() {
 // declare size of two dimensional array and initialize.
 vector<vector<int>> vI2Matrix(3, vector<int>(2,0));

 vI2Matrix[0][0] = 0;
 vI2Matrix[0][1] = 1;
 vI2Matrix[1][1] = 10;
 vI2Matrix[2][0] = 20;
 vI2Matrix[2][1] = 21;

 cout << "Loop by index:" << endl;

 int ii, jj;
 for (ii=0; ii< 3; ii++) {
    for (jj=0; jj < 2; jj++) {
       cout << vI2Matrix[ii][jj] << endl;
    }
 }
}
