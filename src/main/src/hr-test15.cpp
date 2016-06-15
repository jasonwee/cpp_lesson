// https://www.hackerrank.com/challenges/the-time-in-words?h_r=next-challenge&h_v=zen

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string getWords(int h, int m);

int main() {
  int h = 0;
  int m = 0;
  cin >> h;
  cin >> m;
  string time = getWords(h,m);
  cout << time;
  return 0;
}

string getWords(int h, int m) {

  string lookup[] = {"zero", "one", "two", "three", "four", 
                     "five", "six", "seven", "eight", "nine", 
                     "ten", "eleven", "twelve", "thirteen", "fourteen",
                     "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                     "twenty", "twenty one", "twenty two", "twenty three", "twenty four",
                     "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine"
                    };

  if (m == 0) {
    return lookup[h] + " o' clock";
  }
  if (m ==1) {
    return lookup[m] + " minutes past " + lookup[h];
  }
  if ( ( m > 1 && m < 15 ) || ( m > 15 && m < 30)) {
    return lookup[m] + " minutes past " + lookup[h];
  }
  if ( m == 15 ) {
    return "quarter past " + lookup[h];
  }
  if ( m == 30 ) {
    return "half past " + lookup[h];
  }
  if ((m > 30 && m < 45) || (m > 45 && m < 59)) {
    return lookup[60-m] + " minutes to " + lookup[(h+1)%24];
  }
  if (m==45) {
    return "quarter to " + lookup[(h+1)%24];
  }
  if (m==59) {
    return lookup[60-m] + " minute to " + lookup[(h+1)%24];
  }
  return "Error";
}
