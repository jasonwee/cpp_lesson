#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

/*
 * i have no idea what is the challenge about, i just got a java program
 * and convert into cpp.
 */ 
int main() {
  int people = 0;
  int topics = 0;
  cin >> people >> topics;
  //int[][] a = new int[people][topics];
  int a[people][topics];
  for(int i = 0; i < people; i++) {
    int currentArray[topics];
    string currentTopicList = "";
    cin >> currentTopicList;
    for (string::size_type j = 0; j < currentTopicList.size(); j++) {
      currentArray[j] = currentTopicList.at(j) - '0';
    }
    memcpy(a[i], currentArray, sizeof(currentArray));
  }
  int highest = 0;
  int bestTeams = 0;
  int row = sizeof(a)/sizeof(a[0]);
  int cols = sizeof(a[0])/sizeof(a[0][0]);

  for (int i = 0; i < row -1; i++) {
    for (int j = i+1; j < cols; j++) {
      int knowledge = 0;
      for (int x = 0; x < topics; x++) {
        knowledge += (a[i][x] == 1 || a[j][x] == 1) ? 1 : 0;
      }
      if (knowledge > highest) {
        highest = knowledge;
        bestTeams = 1;
      } else if (knowledge == highest) {
        bestTeams += 1;
      }
    }
  }
  cout << highest << endl;
  cout << bestTeams << endl;
}
