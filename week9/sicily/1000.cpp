#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <queue>

struct Node {
  //  char ch;
  int weight;
  int height;
  Node* left;
  Node* right;

  Node(int _w, int _h = 0, Node* _l = NULL, Node* _r = NULL)
      : weight(_w), height(_h), left(_l), right(_r) {}
};

// bool compare(Node* lhs, Node* rhs) { return lhs->weight < rhs->weight; }

void updateHeight(Node* ptr) {
  if (ptr == NULL) return;
  ++(ptr->height);
  updateHeight(ptr->left);
  updateHeight(ptr->right);
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
  Node** arr = new Node*[len];
  for (int i = 0; i < len; ++i) {
    arr[i] = NULL;
  }

  int index = 0;
  for (iter = m.begin(); iter != m.end(); ++iter) {
    arr[index] = new Node(iter->second);
    ++index;
  }

  if (arr[0] == NULL) {
    printf("0\n");
    return 0;
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
    Node* newNode = new Node(n1->weight + n2->weight);
    newNode->left = n1;
    newNode->right = n2;

    // updateHeight(newNode);
    updateHeight(n1);
    updateHeight(n2);

    arr[index - 2] = newNode;
  }

  int sum = 0;
  std::queue<Node*> q;
  q.push(arr[0]);

  while (!q.empty()) {
    Node* ptr = q.front();
    q.pop();

    if (ptr->left == NULL && ptr->right == NULL) {
      sum += ptr->weight * ptr->height;
    }

    if (ptr->left != NULL) {
      q.push(ptr->left);
    }
    if (ptr->right != NULL) {
      q.push(ptr->right);
    }
  }

  printf("%d\n", sum);

  return 0;
}
