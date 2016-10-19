#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int jinzhi = 256;

int rabin_karp(const vector<int>& gate, const vector<int>& key) {
  int n = gate.size();
  int m = key.size();

  if (n < m) return -1;
  int g_hash = 0;
  int k_hash = 0;

  for (int i = 0; i < m; ++i) {
    k_hash = jinzhi * k_hash + key[i];
    g_hash = jinzhi * g_hash + gate[i];
  }

  int h = pow(jinzhi, m - 1);
  for (int j = 0; j <= n - m; ++j) {
    if (k_hash == g_hash) return j;
    if (j < n - m) {
      g_hash = jinzhi * (g_hash - h * gate[j]) + gate[j + m];
    }
  }

  return -1;
}

int main(int argc, char const* argv[]) {
  int n, m;
  while (cin >> m) {
    vector<int> key, gate;
    while (m--) {
      int temp;
      cin >> temp;
      key.push_back(temp);
    }
    cin >> n;
    while (n--) {
      int temp;
      cin >> temp;
      gate.push_back(temp);
    }
    int index = rabin_karp(gate, key);
    if (index >= 0) {
      cout << index << endl;
    } else {
      cout << "no solution" << endl;
    }
  }
  return 0;
}
