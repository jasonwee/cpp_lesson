#include <iostream>

using namespace std;

// https://www.hackerrank.com/challenges/larrys-array

void rotate(int arr[], int a) {
  int temp = arr[a];
  arr[a] = arr[a+1];
  arr[a+1] = arr[a+2];
  arr[a+2] = temp;
}

void sort(int array[], int n) {
  for (int i = 0; i < n -2; i++) {
    for (int j = n - 2 -1; j >= i; j--) {
      while (array[j] > array[j+1] || array[j] > array[j+2]) {
        rotate(array,j);
      }
    }
  }
}

int main() {
  int test = 0;
  cin >> test;

  for (int i = 0; i < test; i++) {
    int n = 0;
    cin >> n;
    int a[n];
    for (int j = 0; j < n; j++) {
      cin >> a[j];
    }
    sort(a, n);
    cout << (a[n-2] < a[n-1] ? "YES":"NO") << endl;
  }
}
