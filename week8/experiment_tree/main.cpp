#include <iostream>
#include "binary_tree.hpp"

// int main(int argc, char const *argv[]) {
//     binaryTree tree;
//     const char a[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
//     for (int i = 0; i < 7; ++i) {
//         tree.insert(const Element_type &child_data, const Element_type
//         &parent_data, bool isLeft)
//     }
//     return 0;
// }

void help() {
  system("clear");
  std::cout << "0 is for the help page" << std::endl;
  std::cout << "1 is insert an element" << std::endl;
  std::cout << "2 is clear an subtree" << std::endl;
  std::cout << "3 is invert the tree" << std::endl;
  std::cout << "4 is to show the tree" << std::endl;
}

int main(int argc, char const *argv[]) {
  help();
  binaryTree tree;

  int choice;

  Element_type data1, data2;
  bool isLeft;
  while (std::cin >> choice) {
    switch (choice) {
      case 0:
        help();
        break;
      case 1:
        std::cout << "Please input the child_data, parent_data and isInsertLeft"
                  << std::endl;
        std::cin >> data1 >> data2 >> isLeft;
        std::cout << tree.insert(data1, data2, isLeft) << std::endl;
        break;
      case 2:
        std::cout << "clear the tree" << std::endl;
        tree.clear();
        break;
      case 3:
        std::cout << "invert the tree" << std::endl;
        tree.invert();
        break;
      case 4:
        std::cout << "SHOWING the TREE" << std::endl;
        tree.display();
        break;
      default:
        std::cout << "Input Invaild" << std::endl;
        break;
    }
  }
  return 0;
}
