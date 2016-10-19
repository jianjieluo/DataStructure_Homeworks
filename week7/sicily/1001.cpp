#include <iostream>
#include <string>

bool isLegal(const char ch) {
  return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') ||
          (ch >= '0' && ch <= '9') || ch == '-' || ch == '_');
}

// bool isLegal(char ch) {
//   if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') ||
//       (ch >= '0' && ch <= '9') || ch == '-' || ch == '_') {
//     return true;
//   }
//   return false;
// }

int main() {
  std::string str;
  // std::cin >> str;
  while (std::cin >> str) {
    if (str.size() == 0) continue;
    for (unsigned int i = 1; i < str.size() - 1; ++i) {
      if (str[i] == '@' && isLegal(str[i - 1]) && isLegal(str[i + 1])) {
        int begin, end;
        for (begin = i - 1; begin >= 0; --begin) {
          if (str[begin] == '.' && str[begin + 1] == '.') {
            break;
          }
          if (str[begin] != '.' && !isLegal(str[begin])) {
            break;
          }
        }
        if (str[begin + 1] == '.') ++begin;
        for (end = i + 1; end < str.size(); ++end) {
          if (str[end] == '.' && str[end - 1] == '.') {
            break;
          }
          if (str[end] != '.' && !isLegal(str[end])) {
            break;
          }
        }
        if (str[end - 1] == '.') --end;

        for (int j = begin + 1; j < end; ++j) {
          std::cout << str[j];
        }
        std::cout << std::endl;
      }
    }
  }
  return 0;
}
