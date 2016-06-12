#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

#define MAX 500


int multiply(int x, int res[], int res_size);
void factorial(int n);

int main() {
    int n = 0;
    cin >> n;
    factorial(n);
    return 0;
}

// This function finds factorial of large numbers and prints them
void factorial(int n)
{
  int res[MAX]; 

  // initialize result
  res[0] = 1;
  int res_size = 1;

  // Apply simple factorial formual n! = 1 * 2 * 3 * .. * n
  for (int x = 2; x <= n; x++)
    res_size = multiply(x, res, res_size);

  for (int i = res_size - 1; i >= 0; i--)
    cout << res[i];
  cout << endl;
}

// This function multiplies x with the number represented by res[].
// res_size is size of res[] or number of digits in the number represented
// by res[]. This function uses simple school mathematics for multiplication.
// This function may value of res_size and returns the new value of res_size
int multiply(int x, int res[], int res_size)
{
  int carry = 0; // initialize carry

  // one by one multiply n with individual digits of res[]
  for (int i = 0; i < res_size; i++)
  {
    int prod = res[i] * x + carry;
    res[i] = prod % 10; // store last digit of 'prod' in res[]
    carry = prod / 10;  // put rest in carry
  }

  // put carry in res and increase result size
  while (carry) {
    res[res_size] = carry % 10;
    carry = carry / 10;
    res_size++;
  }
  return res_size;
}
