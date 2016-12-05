#include <cstring>
#include <iostream>
#include <queue>
#include <string>

struct node {
  int x;
  char y;
  bool operator==(const node& rhs) {
    return (this->x == rhs.x && this->y == rhs.y);
  }
};

const int move[8][2] = {{1, -2}, {1, 2},   {2, 1},  {2, -1},
                        {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};

int getIndex(const node& n) { return (n.x - 1) * 8 + (n.y - 'a'); }
bool can_go(const node& curr, int dx, int dy) {
  int x = curr.x + dx;
  int y = curr.y + dy;
  return (1 <= x && x <= 8 && 'a' <= y && y <= 'h');
}

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    std::string a, b;
    std::cin >> a >> b;
    node start, end;
    start.x = a[1] - '0';
    start.y = a[0];
    end.x = b[1] - '0';
    end.y = b[0];
    std::queue<node> q;
    q.push(start);

    int steps = 0;
    bool visited[64] = {};
    int distance[64];
    for (int i = 0; i < 64; ++i) {
      distance[i] = -1;
    }

    while (!q.empty()) {
      node curr = q.front();
      q.pop();
      int index = getIndex(curr);
      ++distance[index];
      visited[index] = true;
      if (curr == end) {
        steps = distance[index];
        break;
      }

      node temp;
      for (int i = 0; i < 8; ++i) {
        if (can_go(curr, move[i][0], move[i][1])) {
          temp.x = curr.x + move[i][0];
          temp.y = curr.y + move[i][1];
          int new_index = getIndex(temp);
          if (!visited[new_index]) {
            distance[new_index] = distance[index];
            visited[new_index] = true;
            q.push(temp);
          }
        }
      }
    }
    std::cout << "To get from " << a << " to " << b << " takes " << steps
              << " knight moves." << '\n';
  }
  return 0;
}
