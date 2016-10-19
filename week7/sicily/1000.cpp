#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  // std::string str;
  char str[14];
  while (std::cin >> str) {
    int wsum = 0;
    int count = 0;
    for (unsigned int i = 0; i < 11; ++i) {
      if (str[i] != '-') {
        wsum += (str[i] - '0') * (10 - count);
        ++count;
      }
    }

    // std::cout << wsum << std::endl;

    int lastNum = 0;
    for (int i = 0; i < 11; ++i) {
      if ((wsum + i) % 11 == 0) {
        lastNum = i;
        break;
      }
    }
    str[11] = '-';
    // std::cout << lastNum << std::endl;
    if (lastNum == 10) {
      str[12] = 'X';
    } else {
      str[12] = lastNum + '0';
    }
    str[13] = '\0';
    // std::cout << str << std::endl;
    std::cout << str << std::endl;
  }
  return 0;
}
