#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

// https://www.hackerrank.com/challenges/kaprekar-numbers?h_r=next-challenge&h_v=zen

vector<int> numToArray(unsigned long long n){
    vector<int>arr;

    while ( n != 0) {
        arr.push_back(n%10);
        n /= 10;
    }
    reverse(arr.begin(),arr.end());
    return arr;
}

bool isKaprekar(int origin, vector<int> nums){
    int mid = ceil((double)nums.size() / 2);

    int leftLen = nums.size() - mid;
    int rightLen = mid;

    int lsum = 0;
    int rsum = 0;

    int lmult = pow(10,leftLen - 1);
    int rmult = pow(10,rightLen - 1);
    for (int i = 0; i < nums.size(); i++) {
        if (i < leftLen){
            lsum += nums[i]*lmult;
            lmult /= 10;
        }
        else{
            rsum += nums[i]*rmult;
            rmult /= 10;
        }
    }

    return origin == lsum + rsum;

}

int main() {

    int p, q;
    cin >> p >> q;

    vector<int> numbers;

    for (p; p <=q; p++) {
        if (isKaprekar(p,numToArray(pow(p,2))))
            numbers.push_back(p);
    }

    if (numbers.size() == 0) {
        cout << "INVALID RANGE" << endl;
    } else {
      for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
      }
      cout << endl;
    }

    return 0;
}
