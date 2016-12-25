#include <iostream>
#include <stack>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
  Node(int n) : data(n), left(NULL), right(NULL) {}
};

Node *root;
stack<Node *> s;

int getHeight(Node *sub) {
  return sub != NULL ? 1 + max(getHeight(sub->left), getHeight(sub->right)) : 0;
}

void rotLeft(Node *sub, Node *parent) {
  Node *right = sub->right;
  sub->right = right->left;
  right->left = sub;
  if (parent == NULL)
    root = right;
  else
    sub == parent->left ? parent->left = right : parent->right = right;
}

void insert(Node *&sub, int data) {
  if (sub != NULL) {
    s.push(sub);
    insert(data < sub->data ? sub->left : sub->right, data);
  } else
    sub = new Node(data);
}

void rotRight(Node *sub, Node *parent) {
  Node *left = sub->left;
  sub->left = left->right;
  left->right = sub;
  if (parent == NULL)
    root = left;
  else
    sub == parent->left ? parent->left = left : parent->right = left;
}

void clear(Node *&sub) {
  if (sub != NULL) {
    clear(sub->left);
    clear(sub->right);
    delete sub;
  }
}

void balance() {
  Node *sub;
  while (!s.empty()) {
    sub = s.top();
    s.pop();
    int LHeight = getHeight(sub->left);
    int RHeight = getHeight(sub->right);
    if (LHeight - RHeight == 2) {
      if (getHeight(sub->left->right) - getHeight(sub->left->left) == 1)
        rotLeft(sub->left, sub);
      rotRight(sub, s.empty() ? NULL : s.top());
    } else if (RHeight - LHeight == 2) {
      if (getHeight(sub->right->left) - getHeight(sub->right->right) == 1)
        rotRight(sub->right, sub);
      rotLeft(sub, s.empty() ? NULL : s.top());
    }
  }
}

void preorder(Node *root) {
  if (root != NULL) {
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

int main() {
  int T;
  int n, data;
  cin >> T;
  while (T--) {
    root = NULL;
    cin >> n;
    while (n--) {
      cin >> data;
      insert(root, data);
      balance();
    }
    preorder(root);
    cout << endl;
    clear(root);
  }
  return 0;
}
