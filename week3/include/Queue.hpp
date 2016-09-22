#include <cstring>
#include <iostream>
#define MAX 301

typedef char Queue_entry;
enum Error_code2 { success2, overflow2, underflow2 };

// the max number of the content is 300
class Queue {
 public:
  Queue();
  ~Queue();
  Error_code2 push(const Queue_entry data);
  Error_code2 pop();
  Error_code2 display() const;

 private:
  char buffer[MAX];
  int front;
  int rear;
};
