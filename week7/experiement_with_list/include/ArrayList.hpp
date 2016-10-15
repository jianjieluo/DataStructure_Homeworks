#ifndef ARRAYLIST_HPP_
#define ARRAYLIST_HPP_
#include "enum.hpp"

const int MAX = 100;

template <typename List_entry>
class ArrayList {
 private:
  int m_size;
  List_entry m_buffer[MAX];

 public:
  ArrayList() : m_size(0){};
  ~ArrayList(){};

  bool isEmpty() const { return m_size == 0; }
  bool isFull() const { return m_size == MAX - 1; }
  int size() const { return m_size; }

  // Error_code init(const List_entry* init, const int _size);
  Error_code insert(const int position, const List_entry& item);
  Error_code remove(const int position);
  void display() const;
};

#include "../src/ArrayList.cpp"
#endif
