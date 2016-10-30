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
  int moduleChoice;
  binaryTree tree;
  std::cout << "0 for the standard input and other for freedom input"
            << std::endl;

  std::cin >> moduleChoice;
  if (moduleChoice) {
    help();

    int choice;

    Element_type data1, data2;
    bool isLeft;
    while (std::cin >> choice) {
      switch (choice) {
        case 0:
          help();
          break;
        case 1:
          std::cout
              << "Please input the child_data, parent_data and isInsertLeft"
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
  } else {
    const char a[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    tree.insert('R', 'a', 1);

    tree.insert(a[0], 'R', 1);
    tree.insert(a[1], 'R', 0);
    tree.insert(a[2], a[0], 1);
    tree.insert(a[3], a[0], 0);
    tree.insert(a[4], a[1], 1);
    tree.insert(a[5], a[1], 0);
    tree.insert(a[6], a[2], 1);
    tree.insert(a[7], a[2], 0);
    tree.insert(a[8], a[3], 1);
    tree.insert(a[9], a[9], 0);

    std::cout << "The old tree" << std::endl;
    tree.display();
    tree.invert();
    std::cout << "The tree after invert" << std::endl;
    tree.display();
  }
  return 0;
}
