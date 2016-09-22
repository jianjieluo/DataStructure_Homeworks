#include <iostream>
#include <list>
#include <queue>

struct Node {
  int exp;
  int coef;
  Node(int x, int y) : exp(x), coef(y) {}
};

bool filter(const Node& temp) { return temp.exp == 0; }

int main(int argc, char const* argv[]) {
  int m;
  std::cin >> m;
  while (m--) {
    std::queue<Node> p1, p2;
    std::list<Node> ans;
    int n;
    std::cin >> n;
    while (n--) {
      int x, y;
      std::cin >> x >> y;
      p1.push(Node(x, y));
    }
    std::cin >> n;
    while (n--) {
      int x, y;
      std::cin >> x >> y;
      p2.push(Node(x, y));
    }

    while (!(p1.empty() || p2.empty())) {
      Node t1 = p1.front();
      Node t2 = p2.front();
      if (t1.coef > t2.coef) {
        p1.pop();
        ans.push_back(t1);
      } else if (t1.coef < t2.coef) {
        p2.pop();
        ans.push_back(t2);
      } else {
        p1.pop();
        p2.pop();
        ans.push_back(Node((t1.exp + t2.exp), t1.coef));
      }
    }

    if (p1.size() != p2.size()) {
      std::queue<Node> temp = (p1.size() > p2.size()) ? p1 : p2;
      while (!temp.empty()) {
        ans.push_back(temp.front());
        temp.pop();
      }
    }

    ans.remove_if(filter);
    std::cout << ans.size() << std::endl;
    for (std::list<Node>::const_iterator iter = ans.begin(); iter != ans.end();
         ++iter) {
      std::cout << iter->exp << " " << iter->coef << std::endl;
    }
  }
  return 0;
}
