#include <stdio.h>

int root(int x, int y) {
  if (x == y)
    return x;
  else if (x > y)
    return root(x / 2, y);
  else
    return root(x, y / 2);
}

int main() {
  int n, x, y;
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d", &x, &y);
    printf("%d\n", root(x, y));
  }
  return 0;
}
