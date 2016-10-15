#include <iostream>
#include "enum.hpp"

// template <typename List_entry>
// Error_code NodeList<List_entry>::init(const Node<List_entry>* init,
//                                       const int _size) {
//   clear();
//   m_size = _size;
//   m_head = new Node<List_entry>(0, nullptr);
//   for (int i = 0; i < _size; ++i) {
//     this->insert(init[i], i);
//   }
//   return success;
// }

template <typename List_entry>
NodeList<List_entry>::~NodeList() {
  clear();
}

template <typename List_entry>
Error_code NodeList<List_entry>::insert(const int position,
                                        const List_entry& item) {
  if (position < 0) {
    return underflow;
  }
  Node<List_entry>* ptr = m_head;
  for (int i = 0; i < position; ++i) {
    ptr = ptr->next;
    if (ptr == nullptr) {
      return overflow;
    }
  }

  // begin to insert
  Node<List_entry>* temp = new Node<List_entry>(item, ptr->next);
  ptr->next = temp;
  ++m_size;
  return success;
}

template <typename List_entry>
Error_code NodeList<List_entry>::remove(const int position) {
  if (position < 0) {
    return underflow;
  }
  if (position >= m_size) {
    return overflow;
  }
  Node<List_entry>* ptr = m_head;
  for (int i = 0; i < position; ++i) {
    ptr = ptr->next;
  }
  Node<List_entry>* temp = ptr->next;
  ptr->next = temp->next;
  delete temp;
  --m_size;
  return success;
}

template <typename List_entry>
void NodeList<List_entry>::clear() {
  Node<List_entry>* head = m_head->next;
  while (head != nullptr) {
    Node<List_entry>* temp = head;
    head = head->next;
    delete temp;
  }
  m_size = 0;
}

template <typename List_entry>
void NodeList<List_entry>::display() const {
  Node<List_entry>* ptr = m_head;
  std::cout << "The current NodeList is:" << std::endl;
  int judge = true;
  while (ptr->next != nullptr) {
    ptr = ptr->next;
    if (judge) {
      std::cout << ptr->data;
      judge = false;
    } else {
      std::cout << "->" << ptr->data;
    }
  }
  std::cout << std::endl;
}
