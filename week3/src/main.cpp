#include "Queue.hpp"
#include "Stack.hpp"

void help() {
  system("clear");
  std::cout << "----------------Welcome!!----------------" << std::endl;
  std::cout << "0 display the help menu" << std::endl;
  std::cout << "-----------------------------------------" << std::endl;
  std::cout << "1 push an element into the stack" << std::endl;
  std::cout << "2 pop an element from the stack" << std::endl;
  std::cout << "3 display the current stack" << std::endl;
  std::cout << "-----------------------------------------" << std::endl;
  std::cout << "4 push an element into the queue" << std::endl;
  std::cout << "5 pop an element from the queue" << std::endl;
  std::cout << "6 display the current stack" << std::endl;
  std::cout << "------------------------------------------" << std::endl;
  std::cout << "Here is the Error_code:" << std::endl;
  std::cout << "0 for fail" << std::endl;
  std::cout << "1 for success" << std::endl;
  std::cout << "2 for overflow" << std::endl;
  std::cout << "3 for underflow" << std::endl;
}

int main(int argc, char const *argv[]) {
  std::cout << "1 for the standard input and 2 for the test" << std::endl;
  int choice;
  Stack s;
  Queue q;
  std::cin >> choice;
  if (choice == 1) {
    char standard[] = {'C', 'O', 'M', 'P', 'U', 'T', 'E', 'R'};
    for (unsigned int i = 0; i < strlen(standard); ++i) {
      s.push(standard[i]);
      q.push(standard[i]);
    }
    std::cout << "The display of my stack" << std::endl;
    s.display();
    std::cout << "The display of my queue" << std::endl;
    q.display();
  } else if (choice == 2) {
    help();
    char data;
    while (std::cin >> choice) {
      switch (choice) {
        case 0:
          help();
          break;
        case 1:
          std::cout << "Input a data:" << std::endl;
          std::cin >> data;
          std::cout << "The Error code is :" << s.push(data) << std::endl;
          break;
        case 2:
          std::cout << "Pop a data:" << std::endl;
          std::cout << "The Error code is :" << s.pop() << std::endl;
          break;
        case 3:
          std::cout << "Display my stack:" << std::endl;
          std::cout << "The Error code is :" << s.display() << std::endl;
          break;
        case 4:
          std::cout << "Input a data:" << std::endl;
          std::cin >> data;
          std::cout << "The Error code is :" << q.push(data) << std::endl;
          break;
        case 5:
          std::cout << "Pop a data:" << std::endl;
          std::cout << "The Error code is :" << q.pop() << std::endl;
          break;
        case 6:
          std::cout << "Display my queue:" << std::endl;
          std::cout << "The Error code is :" << q.display() << std::endl;
          break;
        default:
          break;
      }
    }
  }
  return 0;
}
