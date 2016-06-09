#include <iostream>

using namespace std;

main() {

  int a = 21;
  int c;

  c = a;
  cout << "Line 1 -  = Operator, Value of c = :" << c << endl;

  c += a;
  cout << "Line 2 - += Operator, Value of c = :" << c << endl;

  c -= a;
  cout << "Line 3 - -= Operator, Value of c = :" << c << endl;

  c *= a;
  cout << "Line 4 - *= Operator, Value of c = :" << c << endl;

  c /= a;
  cout << "Line 5 - /= Operator, Value of c = :" << c << endl;

  c = 200;
  c %= a;
  cout << "Line 6 - %= Operator, Value of c = :" << c << endl;

  c <<= 2;
  cout << "Line 7 - <<= Operator, Value of c = :" << c << endl;

  c >>= 2;
  cout << "Line 8 - >>= Operator, Value of c = :" << c << endl;

  c &= 2;
  cout << "Line 9 - &= Operator, Value of c = :" << c << endl;

  c ^= 2;
  cout << "Line 10 - ^= Operator, Value of c = :" << c << endl;

  c |= 2;
  cout << "Line 11 - |= Operator, Value of c = :" << c << endl;

  return 0;
}
