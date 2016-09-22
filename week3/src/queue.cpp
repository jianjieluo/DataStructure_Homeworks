#include "Queue.hpp"

Queue::Queue() : front(0), rear(-1) { memset(buffer, 0, MAX); }

Queue::~Queue() {}

Error_code2 Queue::push(const Queue_entry data) {
  if ((rear + 2) % MAX == front) return overflow2;
  buffer[++rear] = data;
  return success2;
}

Error_code2 Queue::pop() {
  if ((rear + 1) % MAX == front) return underflow2;
  --front;
  return success2;
}

Error_code2 Queue::display() const {
  int index = front;
  while (index != rear) {
    std::cout << buffer[index] << " ";
    index = (index + 1) % MAX;
  }
  std::cout << buffer[index] << std::endl;
  return success2;
}
