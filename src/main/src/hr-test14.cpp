#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

/* my algo sucks, just translate from java to cpp */
int main() {
  int t;
  cin >> t;
  for (int a = 0; a < t; a++) {
    long b = 0;
    long w = 0;
    cin >> b >> w;
    long x = 0;
    long y = 0;
    long z = 0;
    cin >> x >> y >> z;
    x = x > y ? ((x-y>z) ? y+z : x) : x;
    y = y > x ? ((y-x>z) ? x+z : y) : y;
    cout << (b*x + w*y) << endl;
  }
  return 0;
}
