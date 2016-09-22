#include "Queue.hpp"
#include "Stack.hpp"

void help() {
  std::cout << "----------------Welcome!!----------------" << std::endl;
  std::cout << "0 push an element into the stack" << std::endl;
  std::cout << "1 pop an element from the stack" << std::endl;
  std::cout << "2 display the current stack" << std::endl;
  std::cout << "3 push an element into the queue" << std::endl;
  std::cout << "4 pop an element from the queue" << std::endl;
  std::cout << "5 display the current stack" << std::endl;
}

int main(int argc, char const *argv[]) {
  help();
  int choice;
  Stack s;
  Queue q;
  char data;
  while (std::cin >> choice) {
    switch (choice) {
      case 0:
        std::cin >> data;
        std::cout << s.push(data) << std::endl;
        break;
      case 1:
        std::cout << s.pop() << std::endl;
        break;
      case 2:
        std::cout << s.display() << std::endl;
        break;
      case 3:
        std::cin >> data;
        std::cout << q.push(data) << std::endl;
        break;
      case 4:
        std::cout << q.pop() << std::endl;
        break;
      case 5:
        std::cout << q.display() << std::endl;
        break;
      default:
        break;
    }
  }
  return 0;
}
