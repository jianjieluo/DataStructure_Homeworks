#include <queue>

template <typename T>
void levelTraversal(BinaryNode<T> *root, void (*visit)(T &x)) {
  if (root == NULL) return;
  std::queue<BinaryNode<T> *> q;
  q.push(root);

  while (!q.empty()) {
    BinaryNode<T> *ptr = q.front();
    q.pop();

    visit(ptr->elem);
    if (ptr->left != NULL) {
      q.push(ptr->left);
    }
    if (ptr->right != NULL) {
      q.push(ptr->right);
    }
  }
}
