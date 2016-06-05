#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  float pos = 0;
  int nPos = 0;
  float neg = 0;
  int nNeg = 0;
  float zer = 0;
  int nZer = 0;
  cin >> n;
  vector<int> arr(n);
  for (int arr_i = 0; arr_i < n; arr_i++) {
    cin >> arr[arr_i];
    if (arr[arr_i] > 0) {
       nPos++; 
    } else if (arr[arr_i] < 0) {
       nNeg++; 
    } else {
       nZer++;
    }
  }
  pos = nPos / float(n);
  neg = nNeg / float(n);
  zer = nZer / float(n);
  cout << pos << endl;
  cout << neg << endl;
  cout << zer << endl;
  return 0;
}
