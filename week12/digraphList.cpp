#include <algorithm>
#include <cstring>
#include <iostream>
#include <list>
#include <queue>
#define MAX 100

typedef char VertexType;

struct node {
  int index;
  node* next;
  node(int _i, node* _n = NULL) : index(_i), next(_n) {}
};

struct vertex {
  VertexType data;
  node* next;
};

struct Mgraph {
  int nodeNum;
  int edgeNum;
  // std::list<vertex*> vertexList;
  vertex vertexArray[MAX];
};

bool createGraph(Mgraph& G);
void dfs(const Mgraph& G, int v);
void dfsTravel(const Mgraph& G);
void bfs(const Mgraph& G, int v);
void bfsTravel(const Mgraph& G);
int locate(const Mgraph& G, const VertexType& ch);
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
    VertexType temp;
    std::cin >> temp;
    G.vertexArray[i].data = temp;
    G.vertexArray[i].next = NULL;
  }

  std::cout << "请输入有序数对去表示两个节点之间的关系" << std::endl;

  for (int i = 0; i < G.edgeNum; ++i) {
    std::cout << "请输入第" << i + 1 << "对值" << std::endl;
    std::cin >> ch1 >> ch2;
    int i1 = locate(G, ch1);
    int i2 = locate(G, ch2);
    if (i1 < 0 || i2 < 0) {
      return false;
    }
    if (G.vertexArray[i1].next == NULL) {
      G.vertexArray[i1].next = new node(i2, NULL);
    } else {
      node* ptr = G.vertexArray[i1].next;
      while (ptr->next != NULL) {
        ptr = ptr->next;
      }

      // 现在ptr就在最后一个节点了
      ptr->next = new node(i2, NULL);
    }
  }

  // auto showTheGrapth = [&G]() {
  //   for (int i = 0; i < G.nodeNum; ++i) {
  //     std::cout << G.vertexArray[i].data << "->";
  //     node* ptr = G.vertexArray[i].next;
  //     while (ptr != NULL) {
  //       std::cout << G.vertexArray[ptr->index].data << "->";
  //       ptr = ptr->next;
  //     }
  //     std::cout << std::endl;
  //   }
  // };
  // showTheGrapth();

  return true;
}

int locate(const Mgraph& G, const VertexType& ch) {
  for (int i = 0; i < G.nodeNum; ++i) {
    if (G.vertexArray[i].data == ch) {
      return i;
    }
  }
  return -1;
}

void dfs(const Mgraph& G, int index) {
  if (visited[index] == true) {
    return;
  }
  std::cout << G.vertexArray[index].data << " ";
  visited[index] = true;
  node* ptr = G.vertexArray[index].next;
  while (ptr != NULL) {
    dfs(G, ptr->index);
    ptr = ptr->next;
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
  std::queue<int> q;
  q.push(index);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    if (visited[curr] == false) {
      std::cout << G.vertexArray[curr].data << " ";
      visited[curr] = true;

      node* ptr = G.vertexArray[curr].next;
      while (ptr != NULL) {
        if (visited[ptr->index] == false) {
          q.push(ptr->index);
        }
        ptr = ptr->next;
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
