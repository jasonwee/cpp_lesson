#include <iostream>
#include <cmath>

using namespace std;

// https://www.hackerrank.com/challenges/encryption
int main() {
  
   string s;

   cin >> s;
 
   int len = s.size();

   int row = round (sqrt(len));
   int col;

   if (row >= sqrt(len))
     col = row;
   else 
     col = row + 1;

   for (int j = 0; j < col; ++j) {
     for (int i = j ; i < len; i+= col)
       cout << s[i];
     cout << ' ';
   }
   return 0;
}
