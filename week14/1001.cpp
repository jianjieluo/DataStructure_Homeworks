#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n, m;
    std::cin >> n >> m;

    int inDegree[n + 1];
    // memset(inDegree, 0, n + 1);
    for (int i = 0; i < n + 1; ++i) {
      inDegree[i] = 0;
    }
    std::vector<int>* preRequire = new std::vector<int>[n + 1];
    int* result = new int[n];
    std::priority_queue<int, std::vector<int>, std::greater<int> > readyTasks;

    for (int i = 0; i < m; ++i) {
      int a, b;
      std::cin >> a >> b;
      inDegree[b]++;
      preRequire[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i) {
      if (inDegree[i] == 0) {
        readyTasks.push(i);
      }
    }

    int finshedNum = 0;
    while (!readyTasks.empty()) {
      int curr = readyTasks.top();
      readyTasks.pop();
      result[finshedNum++] = curr;

      for (std::vector<int>::iterator it = preRequire[curr].begin();
           it != preRequire[curr].end(); ++it) {
        --inDegree[*it];
        if (inDegree[*it] == 0) {
          readyTasks.push(*it);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    delete[] result;
    delete[] preRequire;
  }
  return 0;
}
