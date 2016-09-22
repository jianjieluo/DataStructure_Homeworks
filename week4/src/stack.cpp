#include "Stack.hpp"

Stack::~Stack() { clear(); }

bool Stack::empty() const { return m_size == 0; }

Error_code Stack::top() const {
  if (empty()) {
    return underflow;
  } else {
    std::cout << m_top->data << std::endl;
    return success;
  }
}

Error_code Stack::push(const Stack_entry data) {
  try {
    if (m_top == nullptr) {
      m_top = new Node(data, nullptr);
    } else {
      Node* temp = new Node(data, m_top);
      m_top = temp;
    }
  } catch (...) {
    return fail;
  }
  ++m_size;
  return success;
}

Error_code Stack::pop() {
  if (empty())
    return underflow;
  else {
    Node* temp = m_top;
    m_top = m_top->next;
    delete temp;
    --m_size;
    return success;
  }
}

int Stack::size() const { return m_size; }

void Stack::clear() {
  while (!empty()) {
    pop();
  }
}

Error_code Stack::display() const {
  Node* ptr = m_top;
  while (ptr != nullptr) {
    std::cout << ptr->data << " ";
    ptr = ptr->next;
  }
  std::cout << std::endl;
  return success;
}
