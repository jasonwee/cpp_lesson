#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {

  vector<int> actual(3);
  vector<int> expect(3);

  // return on or before date, no charged , fine = 0
  // fine = 15 hackos x (the number of days late)
  // fine = 500 hackos x (the number of months late)
  // fine = 10000 hackos
  
  // 3 spaces separated integers day month year . was actually return.
  // 3 spaces seprated integers day mont year . was expected to return.(due date)
  cin >> actual[0] >> actual[1] >> actual[2];
  cin >> expect[0] >> expect[1] >> expect[2];
  int hackos = 0;

  /* 
  if (expect[2] != actual[2]) {
    hackos += 10000;
    if (expect[1] != actual[1]) {
      int fine = (actual[1] - expect[1]) * 500;
      hackos += fine;
    } else  {
      hackos = (actual[0] - expect[0]) * 15;
    }

  } else if (expect[1] != actual[1]) {
    int fine = (actual[1] - expect[1]) * 500;
    hackos += fine;
  } else {
    hackos = (actual[0] - expect[0]) * 15;
  }
  cout << hackos;
  */

  /*  
  if (expect[2] == actual[2] || actual[2] < expect[2]) {
    if ( expect[1] == actual[1] || actual[1] < expect[1] ) {
      if (expect[0] == actual[0] || actual[0] < expect[1]) {
        hackos = 0;
      } else {
        hackos = (actual[0] - expect[0]) * 15;
      }
    } else {
      hackos = (actual[1] - expect[1]) * 500;
    }
    
  } else {
    hackos = 10000;
  }
  */
  
  if (actual[1] == expect[1] && actual[0] > expect[0])
     hackos = (actual[0]  - expect[0]) * 15;

  if (actual[2] == expect[2] && actual[1] > expect[1])
     hackos = (actual[1] - expect[1]) * 500;

  if (actual[2] > expect[2])
     hackos = 10000;

  cout << hackos;
}


