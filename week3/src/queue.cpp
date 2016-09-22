#include "Queue.hpp"

Queue::Queue() : front(0), rear(-1) { memset(buffer, 0, MAX); }

Queue::~Queue() {}

Error_code Queue::push(const Queue_entry data) {
  if ((rear + 2) % MAX == front) return overflow;
  buffer[++rear] = data;
  return success;
}

Error_code Queue::pop() {
  if ((rear + 1) % MAX == front) return underflow;
  --front;
  return success;
}

Error_code Queue::display() const {
  int index = front;
  while (index != rear) {
    std::cout << buffer[index] << " ";
    index = (index + 1) % MAX;
  }
  std::cout << buffer[index] << std::endl;
  return success;
}
