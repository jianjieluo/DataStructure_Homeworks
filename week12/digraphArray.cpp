#include <cstring>
#include <iostream>
#include <queue>
#define MAX 100

typedef char VertexType;
typedef int EdgeType;

typedef struct {
  VertexType v[MAX];
  EdgeType e[MAX][MAX];
  int nodeNum, edgeNum;
} Mgraph;

bool createGraph(Mgraph& G);
void dfs(const Mgraph& G, int v);
void dfsTravel(const Mgraph& G);
void bfs(const Mgraph& G, int v);
void bfsTravel(const Mgraph& G);
EdgeType locate(const Mgraph& G, const VertexType& ch);
bool visited[MAX];

int main() {
  Mgraph graph;
  if (createGraph(graph)) {
    char choice;
    std::cout << "Create Graph successfully" << std::endl;
    std::cout << "d for the dfs and b for the bfs" << std::endl;
    while (std::cin >> choice) {
      if (choice == 'd') {
        std::cout << "here is the dfs travel :";
        dfsTravel(graph);
      } else if (choice == 'b') {
        std::cout << "here is the bfs travel :";
        bfsTravel(graph);
      }
    }
  } else {
    std::cout << "Create Graph error" << std::endl;
  }
}

bool createGraph(Mgraph& G) {
  VertexType ch1, ch2;
  std::cout << "Please input the nodeNum and edgeNum" << std::endl;
  std::cin >> G.nodeNum >> G.edgeNum;
  std::cout << "Please input the node infomation" << std::endl;
  for (int i = 0; i < G.nodeNum; ++i) {
    std::cin >> G.v[i];
  }

  for (int i = 0; i < G.nodeNum; ++i) {
    for (int j = 0; j < G.nodeNum; ++j) {
      G.e[i][j] = 0;
    }
  }
  std::cout << "请输入有序数对去表示两个节点之间的关系" << std::endl;

  for (int i = 0; i < G.edgeNum; ++i) {
    std::cout << "请输入第" << i + 1 << "对值" << std::endl;
    std::cin >> ch1 >> ch2;
    int i1, i2;
    i1 = locate(G, ch1);
    i2 = locate(G, ch2);
    if (i1 < 0 || i2 < 0) {
      return false;
    }
    G.e[i1][i2] = 1;
  }
  return true;
}

EdgeType locate(const Mgraph& G, const VertexType& ch) {
  for (int i = 0; i < G.nodeNum; ++i) {
    if (G.v[i] == ch) {
      return i;
    }
  }
  return -1;
}

void dfs(const Mgraph& G, int index) {
  if (visited[index] == true) {
    return;
  }
  std::cout << G.v[index] << " ";
  visited[index] = true;
  for (int i = 0; i < G.nodeNum; ++i) {
    if (G.e[index][i] == 1) {
      dfs(G, i);
    }
  }
}

void dfsTravel(const Mgraph& G) {
  memset(visited, 0, MAX);
  for (int i = 0; i < G.nodeNum; ++i) {
    dfs(G, i);
  }
  std::cout << std::endl;
}

void bfs(const Mgraph& G, int index) {
  // std::cout << G.v[index] << " ";
  // visited[index] = true;
  std::queue<int> q;
  q.push(index);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    if (visited[curr] == false) {
      std::cout << G.v[curr] << " ";
      visited[curr] = true;
      for (int i = 0; i < G.nodeNum; ++i) {
        if (G.e[curr][i] == 1) {
          q.push(i);
        }
      }
    }
  }
  std::cout << std::endl;
}

void bfsTravel(const Mgraph& G) {
  memset(visited, 0, MAX);
  for (int i = 0; i < G.nodeNum; ++i) {
    if (!visited[i]) {
      bfs(G, i);
    }
  }
}
