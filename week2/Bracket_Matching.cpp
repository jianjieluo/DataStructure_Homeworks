#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>

const char a[] = {'{', '}', '(', ')', '[', ']'};

bool isDouble(const char lhs, const char rhs) {
  if (a[0] == lhs && a[1] == rhs) return true;
  // if (lhs == a[1] && rhs == a[0]) return true;
  if (lhs == a[2] && rhs == a[3]) return true;
  // if (lhs == a[3] && rhs == a[2]) return true;
  if (lhs == a[4] && rhs == a[5]) return true;
  // if (lhs == a[5] && rhs == a[4]) return true;
  return false;
}

int main(int argc, char const* argv[]) {
  int n;
  std::cin >> n;
  while (n--) {
    std::stack<char> s;
    char line[101];
    std::cin >> line;
    for (unsigned int i = 0; i < strlen(line); ++i) {
      char temp = line[i];
      const char* p = std::find(a, a + strlen(a), temp);
      if (p != a + strlen(a)) {
        if (s.empty()) {
          s.push(temp);
        } else {
          char top = s.top();
          if (isDouble(top, temp)) {
            s.pop();
          } else {
            s.push(temp);
          }
        }
      }
    }
    if (s.empty())
      std::cout << "Yes" << std::endl;
    else
      std::cout << "No" << std::endl;
  }
  return 0;
}
