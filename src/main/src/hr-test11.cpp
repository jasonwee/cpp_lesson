#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * i have no idea what is the challenge about, i just got a java program
 * and convert into cpp.
 */ 
int main() {
/* 
  int t = 0;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n = 0;
    cin >> n;
    int a = 0;
    cin >> a;
    int b = 0;
    cin >> b;

    vector<int> stones(10);

    for (int j = 0; j < n; j++) {
      int sum = (j * a) + ((n-1-j)*b);
      stones[j] = sum;
    }

    for (int c : stones) {
      cout << c << " ";
    }
    cout << endl;
  }
*/
  
  int t = 0;
  cin >> t;

  for (int x = 0; x < t; x++) {
    int n = 0;
    cin >> n;
    int a = 0;
    cin >> a;
    int b = 0;
    cin >> b;

    if (a == b)
      cout << ((n-1) * a);
    else {
      if (a > b) {
        int temp = a;
        a = b;
        b = temp;
      }
      for (int i = 0; i < n; i++)
        cout << (i * b + (n - 1 -i) * a) << " ";
     }
     cout << endl;
  }
 
}
