
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

struct Node {
  Node* left;
  Node* right;
  int val;
};

Node* CreatSearchTree(int value[], int size) {
  int flag = 0;
  // Node* ptr = (Node*)malloc(sizeof(Node));
  Node* ptr = new Node();
  Node* cur;
  Node* temp;

  ptr->left = ptr->right = NULL;
  ptr->val = value[0];

  for (int i = 1; i < size; i++) {
    temp = ptr;
    while (temp != NULL) {
      if (value[i] < temp->val) {
        cur = temp;
        flag = -1;
        temp = temp->left;
      } else {
        cur = temp;
        flag = 1;
        temp = temp->right;
      }
    }

    if (flag == -1) {
      //   cur->left = (Node*)malloc(sizeof(Node));
      cur->left = new Node();
      cur->left->val = value[i];
      cur->left->left = cur->left->right = NULL;
    }

    else if (flag == 1) {
      //   cur->right = (Node*)malloc(sizeof(Node));
      cur->right = new Node();
      cur->right->val = value[i];
      cur->right->left = cur->right->left = NULL;
    }
  }
  return ptr;
}

void preorder(Node* ptr) {
  if (ptr != NULL) {
    cout << ptr->val << ' ';
    preorder(ptr->left);
    preorder(ptr->right);
  }
}

void inorder(Node* ptr) {
  if (ptr != NULL) {
    inorder(ptr->left);
    cout << ptr->val << ' ';
    inorder(ptr->right);
  }
}

int a[3001];

int main() {
  int n;
  while (cin >> n && n) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    Node* ptr = CreatSearchTree(a, n);
    inorder(ptr);
    cout << endl;
    preorder(ptr);
    cout << endl;
  }
  return 0;
}
