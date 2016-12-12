#include <iostream>
using namespace std;
int binSearch(const int s[], const int size, const int target) {
  int res = -1;
  int mid = size / 2;
  int a = 0;
  int b = size - 1;
  while (a != b) {
    mid = (b + a) / 2;
    if (s[mid] == target) {
      res = mid;
      while (s[res + 1] == target) {
        ++res;
      }
      break;
    } else if (s[mid] < target) {
      a = mid + 1;
    } else {
      b = mid;
    }
  }
  return res;
}

int main() {
  int s[8] = {0, 1, 1, 3, 3, 3, 6, 6};
  cout << binSearch(s, 8, 3) << endl;  //输出5
  // cout << binSearch(s, 8, 4) << endl;  //输出-1
  return 0;
}
