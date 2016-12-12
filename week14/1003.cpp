#include <iostream>
using namespace std;

#define MAX 500
#define INF 65536
unsigned int dist[MAX][MAX];
unsigned int tmp[MAX];

inline int min(int n) {
  unsigned int min = INF;
  int re;
  for (int i = 0; i < n; i++) {
    if (tmp[i] > 0 && tmp[i] < min) {
      re = i;
      min = tmp[i];
    }
  }
  return re;
}

int mst_prim(int n) {
  unsigned int re = 0;
  int k;
  for (int i = 0; i < n; i++) tmp[i] = dist[0][i];
  for (int i = 1; i < n; i++) {
    k = min(n);
    re = tmp[k] > re ? tmp[k] : re;
    tmp[k] = 0;
    for (int j = 0; j < n; j++)
      if (dist[k][j] < tmp[j]) tmp[j] = dist[k][j];
  }
  return re;
}

int main() {
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) cin >> dist[i][j];

    cout << mst_prim(n) << endl;
  }
  std::cout << std::endl;
  return 0;
}
