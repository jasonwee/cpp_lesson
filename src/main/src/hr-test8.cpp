#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

  int n=0,i=0,j=0;
  string temp;
  cin >> n;
  vector<vector<int> > a(n, vector<int>(n));
  for (i = 0; i < n; i++) {
    cin >> temp;
    j = 0;
    for (char& c : temp) {
       a[i][j] = c - '0';
       j+=1;
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if ( (i >= 1 ) && (i < n-1) && ( j >= 1 ) && ( j < n-1 ) ) {
        if ( (a[i][j] > a[i-1][j]) && (a[i][j] > a[i][j+1]) && (a[i][j] > a[i+1][j]) && (a[i][j] > a[i][j-1]))
          cout << "X";
        else
          cout << a[i][j];
      } else {
        // the one on the edge will never get print X
        cout << a[i][j];
      }
    }
    cout << endl;
  }
  
}

