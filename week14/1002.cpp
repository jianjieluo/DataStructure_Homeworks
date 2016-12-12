#include <algorithm>
#include <iostream>

#define INF 65536
#define MAX 500
int dist[MAX][MAX];
int relatedDist[MAX];

int min(int n) {
  int min = INF;
  int res;
  for (int i = 0; i < n; i++) {
    if (relatedDist[i] > 0 && relatedDist[i] < min) {
      res = i;
      min = relatedDist[i];
    }
  }
  return res;
}

int prim(int n) {
  int res = 0;
  int k;
  for (int i = 0; i < n; ++i) {
    relatedDist[i] = dist[0][i];
  }
  for (int i = 1; i < n; ++i) {
    // k = *std::min_element(relatedDist, relatedDist + n);
    k = min(n);
    res = relatedDist[k] > res ? relatedDist[k] : res;
    relatedDist[k] = 0;
    for (int j = 0; j < n; ++j) {
      if (dist[k][j] < relatedDist[j]) {
        relatedDist[j] = dist[k][j];
      }
    }
  }
  return res;
}

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        std::cin >> dist[i][j];
      }
    }

    std::cout << prim(n) << std::endl;
    // if (T) std::cout << std::endl;
  }
  return 0;
}
