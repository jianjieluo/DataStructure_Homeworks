#ifndef STACK_HPP_
#define STACK_HPP_
#include <cstring>
#include <iostream>
#include "Error_code.hpp"

typedef char Stack_entry;

struct Node {
  Stack_entry data;
  Node* next;
  Node(Stack_entry temp = '0', Node* n = nullptr) : data(temp), next(n) {}
};

class Stack {
 public:
  Stack() : m_top(nullptr), m_size(0) {}
  ~Stack();
  bool empty() const;
  Error_code top() const;
  Error_code push(const Stack_entry data);
  Error_code pop();
  Error_code display() const;
  int size() const;
  void clear();

 private:
  Node* m_top;
  int m_size;
};

#endif
