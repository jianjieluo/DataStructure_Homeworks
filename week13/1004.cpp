#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

struct Mgraph {
  int vertexNum;
  int edgeNum;
  // int vertex[100];
  bool edges[100][100];
};

bool visited[100];
int level[100];
int isValid;

void createGraph(Mgraph* g) {
  // for (int i = 0; i < g->vertexNum; ++i) {
  //   g->vertex[i] = i + 1;
  // }

  for (int i = 0; i < g->vertexNum; ++i) {
    for (int j = 0; j < g->vertexNum; ++j) {
      g->edges[i][j] = false;
    }
  }

  for (int i = 0; i < g->edgeNum; ++i) {
    int a, b;
    std::cin >> a >> b;
    g->edges[a - 1][b - 1] = true;
  }
}

void bfs(Mgraph* g, int begin) {
  std::queue<int> q;
  q.push(begin);
  // int l = 0;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    if (visited[curr]) {
      isValid = false;
      break;
    }
    visited[curr] = true;
    ++level[curr];

    for (int i = 0; i < g->vertexNum; ++i) {
      if (g->edges[curr][i]) {
        q.push(i);
        level[i] = level[curr];
      }
    }
  }
}

int main() {
  Mgraph* g = NULL;
  while (1) {
    g = new Mgraph;
    int n, m;
    std::cin >> n >> m;
    if (n == 0) break;
    g->vertexNum = n;
    g->edgeNum = m;
    createGraph(g);

    memset(visited, false, 100);
    for (int i = 0; i < 100; ++i) {
      level[i] = -1;
    }
    isValid = true;

    for (int i = 0; i < n; ++i) {
      if (!isValid) break;
      if (!visited[i]) {
        bfs(g, i);
      }
    }

    if (isValid) {
      int depth = *std::max_element(level, level + n);
      std::cout << depth << " ";
      int count[1000] = {};
      for (int i = 0; i < n; ++i) {
        ++count[level[i]];
      }
      std::cout << *std::max_element(count, count + depth + 1) << std::endl;
    } else {
      std::cout << "INVALID" << std::endl;
    }
    delete g;
    g = NULL;
  }
  return 0;
}
