#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  std::map<char, int> m;
  std::map<char, int>::iterator iter;
  std::vector<int> v;
  while (n--) {
    char ch;
    std::cin >> ch;
    bool isInMap = false;
    for (iter = m.begin(); iter != m.end(); ++iter) {
      if (iter->first == ch) {
        isInMap = true;
        break;
      }
    }
    if (isInMap) {
      ++(iter->second);
    } else {
      m[ch] = 1;
    }
  }

  v.clear();
  for (iter = m.begin(); iter != m.end(); ++iter) {
    v.push_back(iter->second);
  }
  std::sort(v.begin(), v.end());
  std::reverse(v.begin(), v.end());

  int len = v.size();
  int sum = 0;
  for (int i = 0; i < len; ++i) {
    sum += (i + 1) * v[i];
  }

  if (len > 1) {
    sum -= v[len - 1];
  }

  printf("%d\n", sum);
  return 0;
}
