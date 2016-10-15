#ifndef NODELIST_HPP_
#define NODELIST_HPP_
// 头结点的单链表中，head指示的是所谓的头结点，它不是实际的结点，不是用来储存数据的。
// 可以这样理解，头结点牺牲了一个储存单元，来化简代码，因为头不可能为空了。
// 或者用来存储一些全局量，比如链表长度，这要依具体需求而定。
#include "enum.hpp"

template <typename List_entry>
struct Node {
  List_entry data;
  Node<List_entry>* next;
  Node<List_entry>(const List_entry& _data, Node<List_entry>* _next)
      : data(_data), next(_next) {}
};

template <typename List_entry>
class NodeList {
 private:
  Node<List_entry>* m_head;
  int m_size;

 public:
  NodeList() : m_size(0) { m_head = new Node<List_entry>(0, nullptr); }
  ~NodeList();

  bool isEmpty() const { return m_size == 0; }
  int size() const { return m_size; }

  // Error_code init(const List_entry* init, const int _size);
  Error_code insert(const int position, const List_entry& item);
  Error_code remove(const int position);
  void clear();
  void display() const;
};

#include "../src/NodeList.cpp"
#endif
