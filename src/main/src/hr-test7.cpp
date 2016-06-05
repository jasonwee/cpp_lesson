#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// NEVER give up on your solution!
int main() {
  string time;
  string n;
  string nTime;
  string ms;
  string f;
  string l;
  cin >> time;
  f = time.substr(0,2);
  ms = time.substr(2,6);
  l = time.substr(8,2);
  if (l == "PM") {
    if ( f == "12") {
      nTime = "12";
    } else if ( f == "01" ) {
      nTime = "13";
    } else if (f == "02") {
      nTime = "14";
    } else if (f == "03") {
      nTime = "15";

    } else if (f == "04") {
      nTime = "16";

    } else if (f == "05") {
      nTime = "17";

    } else if (f == "06") {
      nTime = "18";

    } else if (f == "07") {
      nTime = "19";

    } else if (f == "08") {
      nTime = "20";

    } else if (f == "09") {
      nTime = "21";

    } else if (f == "10") {
      nTime = "22";

    } else if (f == "11") {
      nTime = "23";
    } 
  } else if (l == "AM") {
    if ( f == "12" ) {
      nTime = "00";
    } else {
      nTime = time.substr(0,2);
    }
  }

  cout << nTime << ms ;
  return 0;
}
