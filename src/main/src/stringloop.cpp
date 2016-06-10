#include <iostream>

using namespace std;

int main() {

  string str = "hello world";

  /*  
  for (string::iterator it = str.begin(); it != str.end(); ++it) {
     cout >> *it;
  }
  */

  for (string::size_type i = 0; i < str.size(); ++i) {
    cout << i;
    //cout << str[i] << endl;
  }

}
