/ https://www.hackerrank.com/challenges/the-time-in-words?h_r=next-challenge&h_v=zen

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string getHour(int h);
string getMinute(string m);


int main() {
  int h = 0;
  int m = 0;
  cin >> h;
  cin >> m;
  //string word = "thirteen minutes to six";
  //cout << h << m;
  //cout << word << endl;
  string hour = getHour(h);
  cout << hour << endl;

  string minute = getMinute("00");
  cout << minute << endl;
  return 0;
}

string getMinute(string m) {
  switch(m) {
  case "00"
    return "o' clock";
  }
}

string getHour(int h) {
  switch (h) {
  case  1:
    return "one";
  case  2:
    return "two";
  case  3:
    return "three";
  case  4:
    return "four";
  case  5:
    return "five";
  case  6:
    return "six";
  case  7:
    return "seven";
  case  8:
    return "eight";
  case  9:
    return "nine";
  case 10:
    return "ten";
  case 11:
    return "eleven";
  case 12:
    return "twelve";
  }
}
