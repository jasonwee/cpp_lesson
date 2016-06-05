#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  int d1 = 0;
  int d2 = 0;
  int sum = 0;
  cin >> n;
  vector<vector<int> > a(n, vector<int>(n));
  for (int a_i = 0; a_i < n; a_i++) {
    for (int a_j = 0; a_j < n; a_j++) {
      cin >> a[a_i][a_j];
      if (a_i == a_j) {
        d1 += a[a_i][a_j];
      }
      if (a_i + a_j == (n -1)) {
        d2 += a[a_i][a_j];
      }
    }
  }
  sum = abs(d1 - d2);
  cout << sum;
  return 0;
}
