#include <math.h>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> result;
  int count = 0;
  for (int number = 1; number < 100000000; ++number) {
    auto split = [number](const int n) -> decltype(result) {
      int weishu = pow(10, n);
      int lhs = number / weishu;
      int rhs = number % weishu;
      return std::vector<int>{lhs, rhs};
    };
    // bool judge = false;
    int len = 0;
    int temp = number;
    while (temp) {
      ++len;
      temp /= 10;
    }
    for (int i = 1; i < len; ++i) {
      result = split(i);
      if (result.size() != 2) {
        std::cout << "split error!" << std::endl;
        return 1;
      }
      int lhs = (result[0] + result[1]) * (result[0] + result[1]);
      int rhs = result[0] * pow(10, i) + result[1];
      if (lhs == rhs) {
        std::cout << number << std::endl;
        ++count;
        // std::cout << "The number is a thunder split number" << std::endl;
        // std::cout << result[0] << " " << result[1] << std::endl;
        // judge = true;
      }
    }
    // if (!judge)
    // std::cout << "The number is not a thunder split number" << std::endl;
  }
  std::cout << "The total number is :" << count << std::endl;
  return 0;
}
