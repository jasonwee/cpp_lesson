// https://www.hackerrank.com/challenges/kaprekar-numbers?h_r=next-challenge&h_v=zen

#include <cmath>
#include <cstdio>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

unsigned int getLength(int n);

int main() {
  // n > 0
  // d > 0
  // r right
  // l left
  // l = d -1 
  // l + r = n
  //
  //45 ^^ 2 = 2025
  //20 + 25 = 45
  //
  // p > 0
  // q > 0
  // p < q
  // 0 < p < q < 100 000
  //          2147483 647
  //           10000000000          
 /*  
  1 = 1 X 1 =   1 ~> 1   = 1 yes
  2 = 2 x 2 =   4 ~> 4  != 2 no
  3 = 3 x 3 =   9 ~> 9  != 3 no
  4 = 4 x 4 =  16 ~> 7  != 4 no
  5 = 5 x 5 =  25 ~> 6  != 5 no
  6 = 6 x 6 =  36 ~> 9  != 6 no
  7 = 7 x 7 =  49 ~> 13 != 7 no
  8 = 8 x 8 =  64 ~> 10 != 8 no
  9 = 9 x 9 =  81 ~> 9  != 9 no
*/

  int p = 0;
  int q = 0;
  list<int> res; 

  cin >> p;
  cin >> q;

  for (p ;p <= q; p++) {
    int tmp = p * p;
    //cout << tmp << " ";
    
    int len = getLength(tmp);
    //cout << len << endl;
    
    if (len % 2 == 0) {
      cout << "even " << len;
      res.push_back(p);
    } else {
      cout << "odd " << len;
      res.push_back(p);
    }
    cout << endl;
  }

  for(list<int>::iterator list_iter = res.begin(); list_iter != res.end(); list_iter++)
  {
    cout << *list_iter << endl;
  }
  return 0;
}

unsigned int getLength(int n) {
  unsigned int number_of_digits = 0;

  do {
     ++number_of_digits; 
     n /= 10;
  } while (n);

  return number_of_digits;
}
