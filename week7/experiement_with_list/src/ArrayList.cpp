#include <iostream>
#include "enum.hpp"

// template <typename List_entry>
// Error_code ArrayList<List_entry>::init(const List_entry* init,
//                                        const int _size) {
//   m_size = _size;
//   for (int i = 0; i < _size; ++i) {
//     m_buffer[i] = init[i];
//   }
//   return success;
// }

template <typename List_entry>
Error_code ArrayList<List_entry>::insert(const int position,
                                         const List_entry& item) {
  if (isFull() || position > m_size) {
    return overflow;
  }
  if (position < 0) {
    return underflow;
  }
  for (int i = m_size - 1; i >= position; --i) {
    m_buffer[i + 1] = m_buffer[i];
  }
  m_buffer[position] = item;
  ++m_size;
  return success;
}

template <typename List_entry>
Error_code ArrayList<List_entry>::remove(const int position) {
  if (isEmpty() || position < 0) {
    return underflow;
  }
  if (position > m_size - 1) {
    return overflow;
  }
  for (int i = position; i < m_size - 1; ++i) {
    m_buffer[i] = m_buffer[i + 1];
  }
  --m_size;
  return success;
}

template <typename List_entry>
void ArrayList<List_entry>::display() const {
  std::cout << "The current ArrayList is:" << std::endl;
  for (int i = 0; i < m_size; ++i) {
    if (i == 0) {
      std::cout << m_buffer[i];
    } else {
      std::cout << "->" << m_buffer[i];
    }
  }
  std::cout << std::endl;
}
