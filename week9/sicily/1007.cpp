#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <vector>

// try to use a vector to store the path and when find the right node, do it.

struct Node {
  int weight;
  char ch;
  int path;
  int height;
  Node* left;
  Node* right;

  Node(int _w, char _ch = 'a', int _p = 0, Node* _l = NULL, Node* _r = NULL)
      : weight(_w), ch(_ch), path(_p), left(_l), right(_r) {}
};

Node** arr = new Node*[101];
std::vector<int> path;

// void showPath(Node* ptr) {
//   if (ptr == NULL) return;
//   std::cout << ptr->path;
//
//   showPath(ptr->right);
//   showPath(ptr->left);
// }

void travel(Node* ptr) {
  if (ptr == NULL) return;

  path.push_back(ptr->path);

  if (ptr->left == NULL && ptr->right == NULL) {
    std::cout << ptr->ch << " " << ptr->weight << " ";
    for (std::vector<int>::iterator it = path.begin() + 1; it != path.end();
         ++it) {
      //   if (it != path.begin()) {
      //     printf(" ");
      //   }
      printf("%d", *it);
    }
    printf("\n");
    path.pop_back();
  }

  travel(ptr->right);
  travel(ptr->left);
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
  for (iter = m.begin(); iter != m.end(); ++iter) {
    arr[index] = new Node(iter->second, iter->first);
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
    newNode->right = n1;
    newNode->left = n2;
    n1->path = 1;
    n2->path = 0;

    arr[index - 2] = newNode;
  }

  travel(arr[0]);

  for (int i = 0; i < len; ++i) {
    delete[] arr[i];
  }
  delete[] arr;
  return 0;
}
