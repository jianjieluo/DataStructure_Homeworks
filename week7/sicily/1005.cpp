#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

inline bool isNum(const char ch) { return (ch >= '0' && ch <= '9'); }

int getLen(const std::vector<int>& v) {
  int n = v.size();
  int times = 0;
  for (int i = 0; i < n; ++i) {
    times += v[i] * pow(10, n - 1 - i);
  }
  return times;
}

int main(int argc, char const* argv[]) {
  std::string str;
  while (1) {
    std::cin >> str;
    if (str == "XXX") break;

    unsigned int strLen = str.size();
    for (unsigned int i = 0; i < strLen; ++i) {
      if (!isNum(str[i])) {
        std::cout << str[i];
      } else {
        std::vector<int> len;
        for (unsigned int j = i; j < strLen; ++j) {
          if (isNum(str[j])) {
            len.push_back(str[j] - '0');
          } else {
            break;
          }
        }

        int times = getLen(len);
        for (int j = 1; j < times; ++j) {
          std::cout << str[i - 1];
        }
        i = i + len.size() - 1;
      }
    }
    std::cout << std::endl;
  }
  return 0;
}
