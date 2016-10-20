#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isDouble(const int lhs, const int rhs) {
  return ((lhs == 2 * rhs) || (rhs == 2 * lhs));
}

int main(int argc, char const* argv[]) {
  int n;
  cin >> n;
  std::vector<int> v;
  while (n--) {
    v.clear();
    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
      int temp;
      std::cin >> temp;
      v.push_back(temp);
    }

    int count = 0;
    int vLen = v.size();
    for (int i = 0; i < vLen - 1; ++i) {
      for (int j = i + 1; j < vLen; ++j) {
        if (isDouble(v[i], v[j])) {
          ++count;
        }
      }
    }
    std::cout << count << std::endl;
  }
  return 0;
}
