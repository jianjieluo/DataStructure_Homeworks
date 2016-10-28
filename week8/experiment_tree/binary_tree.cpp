#include "binary_tree.hpp"
#include <cmath>
#include <cstdio>
#include <iostream>

static void swap(Node*& lhs, Node*& rhs) {
  Node* temp = lhs;
  lhs = rhs;
  rhs = temp;
}

binaryTree::binaryTree() : m_size(0), m_root(nullptr) {}

binaryTree::~binaryTree() { remove(m_root); }

Node* binaryTree::search(Node* ptr, const Element_type& t_data) const {
  if (ptr == nullptr) return nullptr;
  if (ptr->data == t_data) return ptr;
  Node* t = nullptr;
  if (nullptr != (t = search(ptr->lchild, t_data)))
    return t;
  else
    return search(ptr->rchild, t_data);
  // search(ptr->lchild, t_data);
  // search(ptr->rchild, t_data);
}

Error_code binaryTree::insert(const Element_type& child_data,
                              const Element_type& parent_data, bool isLeft) {
  if (empty()) {
    m_root = new Node(child_data, 1);
    ++m_size;
    return success;
  }

  Node* parent = find(parent_data);
  if (!parent) {
    return no_parent;
  } else {
    if (isLeft) {
      if (parent->lchild != nullptr)
        return not_null;
      else {
        parent->lchild = new Node(child_data, parent->floor + 1);
        m_size++;
        return success;
      }
    } else {
      if (parent->rchild != nullptr) {
        return not_null;
      } else {
        parent->rchild = new Node(child_data, parent->floor + 1);
        ++m_size;
        return success;
      }
    }
  }
}

void binaryTree::remove(Node* t_root) {
  if (t_root == nullptr) {
    return;
  }
  remove(t_root->lchild);
  remove(t_root->rchild);
  delete t_root;
  --m_size;
}

void binaryTree::invert(Node* parent) {
  // 如果需要提高效率的话，可以在这个if中间加上排除叶节点的情况
  if (parent == nullptr) {
    return;
  } else {
    swap(parent->lchild, parent->rchild);
    invert(parent->lchild);
    invert(parent->rchild);
  }
}

void binaryTree::display() const { show(m_root); }

void binaryTree::show(const Node* ptr) const {
  if (ptr == nullptr) return;
  int t_floor = ptr->floor;
  while (--t_floor) {
    std::cout << "    ";
  }
  std::cout << ptr->data << std::endl;

  show(ptr->lchild);
  show(ptr->rchild);
}
