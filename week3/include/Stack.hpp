#include <cstring>
#include <iostream>

typedef char Stack_entry;
enum Error_code1 { success, fail, overflow, underflow };

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
  Error_code1 top() const;
  Error_code1 push(const Stack_entry data);
  Error_code1 pop();
  Error_code1 display() const;
  int size() const;
  void clear();

 private:
  Node* m_top;
  int m_size;
};
