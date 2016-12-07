#include <iostream>
#define MAX 100001
int id[MAX];

int find(int p) {
  while (p != id[p]) {
    id[p] = id[id[p]];
    p = id[p];
  }
  return p;
}

int main() {
  for (int i = 0; i < MAX; ++i) {
    id[i] = i;
  }

  int n, m;
  while (std::cin >> n >> m) {
    int pRoot = find(n);
    int qRoot = find(m);
    if (pRoot == qRoot) {
      continue;
    } else {
      id[pRoot] = qRoot;
      std::cout << n << " " << m << std::endl;
    }
  }
  return 0;
}
