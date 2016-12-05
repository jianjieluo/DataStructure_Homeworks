#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#define MAX 1000

struct Mgraph {
  int vertex[MAX];
  bool edge[MAX][MAX];
  int vertexNum;
  int edgeNum;
};

bool visited[MAX];
int distance[MAX];

void createGraph(Mgraph* g) {
  std::cin >> g->vertexNum >> g->edgeNum;
  for (int i = 0; i < g->vertexNum; ++i) {
    g->vertex[i] = i + 1;
  }

  for (int i = 0; i < g->vertexNum; ++i) {
    for (int j = 0; j < g->vertexNum; ++j) {
      g->edge[i][j] = false;
    }
  }

  for (int count = 0; count < g->edgeNum; ++count) {
    int i, j;
    std::cin >> i >> j;
    g->edge[i - 1][j - 1] = g->edge[j - 1][i - 1] = true;
  }
}

void bfs(const Mgraph* g, int begin) {
  std::queue<int> q;
  q.push(begin);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    visited[curr] = true;
    ++distance[curr];

    for (int i = 0; i < g->vertexNum; ++i) {
      if (g->edge[curr][i]) {
        if (!visited[i]) {
          distance[i] = distance[curr];
          q.push(i);
          visited[i] = true;
        }
      }
    }
  }
}

int main() {
  Mgraph* g = new Mgraph;
  createGraph(g);

  memset(visited, false, MAX);
  for (int i = 0; i < g->vertexNum; ++i) {
    distance[i] = -1;
  }

  // for (int i = 0; i < g->vertexNum; ++i) {
  //   bfs(g, i);
  // }
  bfs(g, 0);

  for (int i = 0; i < g->vertexNum; ++i) {
    std::cout << distance[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
