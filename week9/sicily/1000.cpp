#include <algorithm>
#include <cstdio>
#include <iostream>
#include <list>
#include <map>

struct Node {
  int weight;
  int height;
  Node* left;
  Node* right;
  Node* parent;

  Node(int _w, int _h, Node* _l = NULL, Node* _r = NULL, Node* _p = NULL)
      : weight(_w), height(_h), left(_l), right(_r), parent(_p) {}
};

int main(int argc, char const* argv[]) {
  int n;
  scanf("%d", &n);
  std::map<char, int> m;
  std::map<char, int>::iterator iter;
  std::list<int> li;
  while (n--) {
    char ch;
    std::cin >> ch;
    bool isInMap = false;
    for (iter = m.begin(); iter != m.end(); ++iter) {
      if (iter->first == ch) {
        isInMap = true;
        break;
      }
    }
    if (isInMap) {
      ++(iter->second);
    } else {
      m[ch] = 1;
    }
  }

  li.clear();
  for (iter = m.begin(); iter != m.end(); ++iter) {
    li.push_back(iter->second);
  }

  if (li.empty()) {
    printf("0\n");
    return 0;
  }
  if (li.size() == 1) {
    printf("%d\n", li.front());
    return 0;
  }

  while (li.size() > 1) {
    std::sort(li.begin(), li.end());
    int lhs = li.front();
    li.pop_front();
    int rhs = li.front();
    li.pop_front();
  }

  return 0;
}
