#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {

  char str1[10] = "Hello";
  char str2[10] = "World";
  char str3[10];
  int len;

  strcpy(str3, str1);
  cout << "strcpy(str3, str1): " << str3 << endl;

  // concatenates str1 and str2
  strcat( str1, str2);
  cout << "strcat( str1, str2): " << str1 << endl;
 
  // total lenghth of str1 after concatenation
  len = strlen(str1);
  cout << "strlen(str1) : " << len << endl;

  string str4 = "Hello";
  string str5 = "World";
  string str6;
  int  llen ;

  // copy str4 into str6
  str6 = str4;
  cout << "str3 : " << str6 << endl;
 
  // concatenates str4 and str5
  str6 = str4 + str5;
  cout << "str4 + str5 : " << str6 << endl;
  
  // total lenghth of str3 after concatenation
  len = str6.size();
  cout << "str6.size() :  " << len << endl;
 
  return 0;
}
