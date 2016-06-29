#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.hackerrank.com/challenges/angry-professor
int main(){

    int t = 0;
    cin >> t;

    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        int count = 0;

        while (n > 0) {
           int s = 0;
           cin >> s;
           if (s <= 0) {
             count++;
           }
           n--;
        }
        if (count >= k)
          cout << "NO" << endl;
        else
          cout << "YES" << endl;
    }

    return 0;
}
