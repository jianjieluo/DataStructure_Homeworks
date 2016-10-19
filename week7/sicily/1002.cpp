#include <iostream>
#include <string>
#include <vector>

void handle(const std::string& test) {
  int len = test.length();
  if (len == 0) return;

  bool isBlank = true;
  for (int i = 0; i < len; ++i) {
    if (test[i] != ' ') {
      isBlank = false;
      break;
    }
  }
  if (isBlank) return;

  // 完善它的长度是单数的情况
  if (len % 2 != 0) ++len;

  for (int i = len / 2 - 1; i >= 0; --i) {
    std::cout << test[i];
  }
  for (int i = len - 1; i >= len / 2; --i) {
    std::cout << test[i];
  }
  std::cout << std::endl;
}

int main(int argc, char const* argv[]) {
  std::string test;
  std::vector<std::string> v;

  while (getline(std::cin, test)) {
    v.push_back(test);
  }

  // std::cout << v.size() << std::endl;
  if (v.size() < 2) {
    handle(v[0]);
  } else {
    for (unsigned int i = 0; i < v.size() - 1; i += 2) {
      handle(v[i + 1]);
      handle(v[i]);
    }
    // if (v.size() % 2 != 0) {
    //   handle(v.back());
    // }
  }

  return 0;
}
