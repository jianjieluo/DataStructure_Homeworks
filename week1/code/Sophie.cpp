#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  string str;
  int front_num, back_num;
  for (int num = 1; num < 100000000; num++) {
    stringstream ss;
    ss << num;
    str = ss.str();
    int length = str.length();
    for (int i = 1; i < length; i++) {
      int div = pow(10, i);
      front_num = num / div;
      back_num = num % div;
      if (num == pow(front_num + back_num, 2)) {
        cout << num << endl;
        break;
      }
    }
  }
  return 0;
}
