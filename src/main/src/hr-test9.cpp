#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

char shiftUpper(char s, int k);
char shiftLower(char s, int k);

int main() {
  int n;
  cin >> n;
  string s = "";
  cin >> s;
  int k = 0;
  cin >> k;
  for (char & c : s) {
    char n = '\0';
    if (c >= 65 && c <= 90) {
      n = shiftUpper(c, k);
    } else if (c >= 97 && c <= 122) {
      n = shiftLower(c, k);
    } else {
      n = c;
    }
    cout << n;
  }

  return 0;
}

char shiftLower(char s1, int shift) {
  // 0 <= shift <= 100
  // 65 = A 90 = Z
  // 97 = a 122 = z
  int b = s1 + shift;
  if (b >= 97 && b <= 122) {
    return (char)b;
  } else {
    b = (shift % 26) + s1;
    if ( b > 122) {
      return (char)((b - 122) + 97 - 1);
    }
    return (char)b;
  }
}

char shiftUpper(char s1, int shift) {
  // 0 <= shift <= 100
  // 65 = A 90 = Z
  // 97 = a 122 = z
  int b = s1 + shift;
  if (b >= 65 && b <= 90) {
    return (char)b;
  } else {
    b = (shift % 26) + s1;
    if ( b > 90) {
      return (char)((b - 90) + 65 - 1);
    }
    return (char)b;
  }
 
}
