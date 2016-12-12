#include <algorithm>
#include <cstdio>
// #include <iostream>
#include <map>

int main(int argc, char const *argv[]) {
  std::map<int, int> map;
  int n;
  bool isFirst = true;
  while (scanf("%d", &n) != EOF) {
    if (n == 0) continue;
    map.clear();
    if (isFirst) {
      isFirst = false;
    } else {
      printf("\n");
    }
    while (n--) {
      int temp;
      scanf("%d", &temp);
      //   std::map<int, int>::iterator iter = map.find(temp);
      if (map.find(temp) == map.end()) {
        map[temp] = 1;
      } else {
        // iter->second += 1;
        map[temp] += 1;
      }
    }

    for (std::map<int, int>::const_iterator iter = map.begin();
         iter != map.end(); ++iter) {
      printf("%d %d\n", iter->first, iter->second);
    }
  }

  return 0;
}
