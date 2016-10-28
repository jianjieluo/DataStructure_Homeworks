#ifndef BINARY_TREE_HPP_
#define BINARY_TREE_HPP_
#include <vector>

enum Error_code { not_null, no_parent, success };
typedef char Element_type;

struct Node {
  Element_type data;
  Node* lchild;
  Node* rchild;

  Node(Element_type _data, Node* _lhs = nullptr, Node* _rhs = nullptr)
      : data(_data), lchild(_lhs), rchild(_rhs) {}
};

class binaryTree {
 private:
  int m_size;
  Node* m_root;
  Node* search(Node* ptr, const Element_type& t_data) const;
  void show(const Node* ptr) const;

 public:
  binaryTree();
  ~binaryTree();
  Node* find(const Element_type& t_data) const {
    return search(m_root, t_data);
  }
  Error_code insert(const Element_type& child_data,
                    const Element_type& parent_data, bool isLeft);
  void remove(Node* t_root);
  void display() const;
  bool empty() const { return m_root == nullptr; }
  void invert();
};

#endif
