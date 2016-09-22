#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#define maxn 1005

bool edges[maxn][maxn];
int color[maxn];
bool can_sort;

void dfs(int pos, int color_, int n) {
  color[pos] = color_;
  for (int i = 0; i < n; ++i) {
    if (edges[pos][i]) {
      if (color[i] == color_) {
        can_sort = false;
        break;
      } else if (!color[i]) {
        dfs(i, 3 - color_, n);
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  int n;
  int num[maxn] = {0};
  int min[maxn] = {0};
  while (std::cin >> n) {
    memset(color, 0, maxn);
    for (int i = 0; i < maxn; ++i) {
      memset(edges[i], 0, maxn);
      // color[i] = 0;
      // for (int j = 0; j < maxn; ++j) {
      //   edges[i][j] = false;
      // }
    }
    can_sort = true;

    // input
    for (int i = 0; i < n; ++i) {
      std::cin >> num[i];
    }
    for (int i = n - 1; i >= 0; --i) {
      if (i == n - 1) {
        min[i] = num[i];
      } else {
        min[i] = std::min(num[i], min[i + 1]);
      }
    }

    // true means the two element can't be put in the same stack
    // so the 2 elements should be print 2 different color.
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (num[i] < num[j] && min[j] < num[i]) {
          edges[i][j] = edges[j][i] = true;
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      if (!color[i]) {
        dfs(i, 1, n);
      }
    }

    std::stack<int> s1, s2;
    std::string operation;
    if (can_sort) {
      int output = 1;
      int pos = 0;
      while (output <= n) {
        if (color[pos] == 1) {
          operation += "a";
          s1.push(num[pos++]);
        }
        while (!s1.empty() && s1.top() == output) {
          s1.pop();
          operation += "b";
          output++;
        }

        // what is this for ?????
        if (color[pos] == 1 && (s1.empty() || s1.top() > num[pos])) {
          continue;
        }

        while (!s2.empty() && s2.top() == output) {
          // cout << "Pop: " << s2.top() << " d" << endl;
          s2.pop();
          operation += "d";
          output++;
        }

        if (color[pos] == 2) {
          operation += "c";
          s2.push(num[pos++]);
        }
      }
      for (unsigned int i = 0; i < operation.size(); ++i) {
        if (i) {
          std::cout << " ";
        }
        std::cout << operation[i];
      }
      std::cout << std::endl;
    } else {
      std::cout << "0" << std::endl;
    }
  }
  return 0;
}
