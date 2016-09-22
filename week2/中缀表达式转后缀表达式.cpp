#include <cstring>
#include <iostream>
#include <stack>

bool isLow(const char lhs, const char rhs) {
  int a, b;
  if (lhs == '#') return true;
  if (lhs == '+' || lhs == '-')
    a = 0;
  else
    a = 1;
  if (rhs == '+' || rhs == '-')
    b = 0;
  else
    b = 1;
  return a < b;
}

int main(int argc, char const *argv[]) {
  char a[300];
  std::cin >> a;
  std::stack<char> operation;
  operation.push('#');

  for (unsigned int i = 0; i < strlen(a); ++i) {
    char temp = a[i];
    if (temp == '+' || temp == '-' || temp == '*' || temp == '/' ||
        temp == '%') {
      while (!isLow(operation.top(), temp)) {
        std::cout << operation.top();
        operation.pop();
      }
      operation.push(temp);
    } else {
      std::cout << temp;
    }
  }
  while (operation.size() != 1) {
    std::cout << operation.top();
    operation.pop();
  }
  // std::cout << std::endl;
  return 0;
}
