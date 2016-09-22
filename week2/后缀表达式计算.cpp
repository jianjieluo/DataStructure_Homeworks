#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>

const char operation[] = {'+', '-', '*', '/'};
double calculate(double lhs, double rhs, char operation) {
  if (operation == '+') return lhs + rhs;
  if (operation == '-') return rhs - lhs;
  if (operation == '*') return lhs * rhs;
  return rhs / lhs;
}

int main(int argc, char const* argv[]) {
  int T;
  std::cin >> T;
  while (T--) {
    std::stack<double> buffer;
    // char str[101];
    std::string str;
    std::cin >> str;
    for (unsigned int i = 0; i < str.size(); ++i) {
      const char* p = std::find(operation, operation + 4, str[i]);
      if (p != operation + 4) {
        double lhs = buffer.top();
        buffer.pop();
        double rhs = buffer.top();
        buffer.pop();
        buffer.push(calculate(lhs, rhs, str[i]));
      } else {
        buffer.push(str[i] - 'a' + 1);
      }
    }
    printf("%.2lf\n", buffer.top());
  }
  return 0;
}
