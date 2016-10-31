#include <iostream>
#include <string>

int main() {
  std::string pre, post;
  std::cin >> pre >> post;
  int type = 1;

  int len = pre.size();
  for (int i = 0; i < len - 1; ++i) {
    int j = post.find(pre[i]);
    if (j == 0) continue;
    if (post[j - 1] == pre[i + 1]) {
      type *= 2;
    }
  }
  std::cout << type << std::endl;
  return 0;
}
