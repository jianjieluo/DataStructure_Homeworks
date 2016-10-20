#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isRight(const string& lhs, const string& rhs) {
  if (lhs.length() != rhs.length()) return false;
  const char* a = lhs.c_str();
  const char* b = rhs.c_str();
  for (unsigned int i = 0; i < lhs.length(); ++i) {
    int temp = a[i] + b[i];
    if (temp != 149 && temp != 138) {
      return false;
    }
  }
  return true;
}

int main(int argc, char const* argv[]) {
  int n;
  cin >> n;
  std::vector<string> v;
  while (n--) {
    v.clear();
    int m;
    cin >> m;
    while (m--) {
      string temp;
      cin >> temp;
      v.push_back(temp);
    }

    m = v.size();
    bool* color = new bool[m];
    memset(color, 0, m);
    int count = 0;
    for (int i = 0; i < m - 1; ++i) {
      if (color[i]) continue;
      for (int j = i + 1; j < m; ++j) {
        if (color[j]) continue;
        if (isRight(v[i], v[j])) {
          ++count;
          color[i] = true;
          color[j] = true;
          // 重点，找到了一对之后两个都要进行改变。
          break;
        }
      }
    }
    cout << count << endl;
    delete[] color;
  }
  return 0;
}
