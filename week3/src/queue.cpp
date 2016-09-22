#include "Queue.hpp"

Queue::Queue() : front(0), rear(-1) { memset(buffer, 0, MAX); }

Queue::~Queue() {}

bool Queue::full() const { return (rear + 2) % MAX == front; }
bool Queue::empty() const { return (rear + 1) % MAX == front; }

Error_code Queue::push(const Queue_entry data) {
  if (full()) return overflow;
  rear = (rear + 1) % MAX;
  buffer[rear] = data;
  return success;
}

Error_code Queue::pop() {
  if (empty()) return underflow;
  front = (front + 1) % MAX;
  return success;
}

Error_code Queue::display() const {
  if (empty()) {
    std::cout << "The queue is empty now!" << std::endl;
  } else {
    int index = front;
    while (index != rear) {
      std::cout << buffer[index] << " ";
      index = (index + 1) % MAX;
    }
    std::cout << buffer[index] << std::endl;
  }
  return success;
}
