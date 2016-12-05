#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

struct Node {
  int weight;
  std::string path;
  char ch;
  Node* left;
  Node* right;

  Node(int _w, std::string _p, char _ch = 'a', Node* _l = NULL, Node* _r = NULL)
      : weight(_w), path(_p), ch(_ch), left(_l), right(_r) {}
};

Node** arr = new Node*[101];

void bfs_travel(Node* root) {
  if (root == NULL) return;
  std::queue<Node*> q;
  q.push(root);

  while (!q.empty()) {
    Node* curr = q.front();
    q.pop();

    if (curr->left == NULL && curr->right == NULL) {
      std::cout << curr->ch << " " << curr->weight << " " << curr->path
                << std::endl;
    } else {
      if (curr->left != NULL) {
        q.push(curr->left);
      }
      if (curr->right != NULL) {
        q.push(curr->right);
      }
    }
  }
}

int main(int argc, char const* argv[]) {
  int n;
  scanf("%d", &n);
  std::map<char, int> m;
  std::map<char, int>::iterator iter;
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

  int len = m.size();
  for (int i = 0; i < len; ++i) {
    arr[i] = NULL;
  }

  int index = 0;
  std::string empty_path = "";
  for (iter = m.begin(); iter != m.end(); ++iter) {
    arr[index] = new Node(iter->second, empty_path, iter->first);
    ++index;
  }

  // create huffman tree
  for (; index > 1; --index) {
    for (int i = index - 1; i > 0; --i) {
      for (int j = 0; j < i; ++j) {
        if (arr[j]->weight < arr[j + 1]->weight) {
          Node* temp = arr[j + 1];
          arr[j + 1] = arr[j];
          arr[j] = temp;
        }
      }
    }

    Node* n1 = arr[index - 2];
    Node* n2 = arr[index - 1];
    Node* newNode = new Node(n1->weight + n2->weight, empty_path);
    newNode->right = n1;
    newNode->left = n2;
    n1->path += "1";
    n2->path += "0";

    arr[index - 2] = newNode;
  }

  // begin to travel the tree
  bfs_travel(arr[0]);
  return 0;
}
