#include <cstring>
#include <iostream>
#include "ArrayList.hpp"
#include "NodeList.hpp"

void help() {
  std::cout << "The report messages are list below" << std::endl;
  std::cout << "0 : fail" << std::endl;
  std::cout << "1 : success" << std::endl;
  std::cout << "2 : overflow" << std::endl;
  std::cout << "3 : underflow" << std::endl;
  std::cout << "----------------------------" << std::endl;
  std::cout << "End the experiment with EOF" << std::endl;
  std::cout << "You can use the following command to control the 2 list"
            << std::endl;
  std::cout << "0 -> help" << std::endl;
  std::cout << "1 -> ArrayList: insert an element" << std::endl;
  std::cout << "2 -> ArrayList: remove an element" << std::endl;
  std::cout << "3 -> ArrayList: display the current element" << std::endl;
  std::cout << "4 -> NodeList: insert an element" << std::endl;
  std::cout << "5 -> NodeList: remove an element" << std::endl;
  std::cout << "6 -> NodeList: display the current element" << std::endl;
}

int main(int argc, char const *argv[]) {
  // choose the mode of the experiment
  std::cout << "Choose 1 for specific initialization and others for no "
               "specific initialization"
            << std::endl;
  int choice;
  std::cin >> choice;

  // initialize the 2 list
  ArrayList<char> arrlist;
  NodeList<char> nodelist;
  if (choice == 1) {
    const char init[] = {'C', 'O', 'M', 'P', 'U', 'T', 'E', 'R'};
    for (int i = strlen(init) - 1; i >= 0; --i) {
      arrlist.insert(0, init[i]);
      nodelist.insert(0, init[i]);
    }
  }
  std::cout << "This experiment's List_entry is char" << std::endl;

  // begin to check
  help();
  char data = '0';
  int position = 0;
  while (std::cin >> choice) {
    switch (choice) {
      case 0:
        system("clear");
        help();
        break;
      case 1:
        std::cout << "Input the data and the position" << std::endl;
        std::cin >> data >> position;
        std::cout << arrlist.insert(position, data) << std::endl;
        break;
      case 2:
        std::cout << "Input the position you want to move from the ArrayList"
                  << std::endl;
        std::cin >> position;
        std::cout << arrlist.remove(position) << std::endl;
        break;
      case 3:
        arrlist.display();
        break;
      case 4:
        std::cout << "Input the data and the position" << std::endl;
        std::cin >> data >> position;
        std::cout << nodelist.insert(position, data) << std::endl;
        break;
      case 5:
        std::cout << "Input the position you want to move from the ArrayList"
                  << std::endl;
        std::cin >> position;
        std::cout << nodelist.remove(position) << std::endl;
        break;
      case 6:
        nodelist.display();
        break;
      default:
        std::cout << "Invalid input, please try again" << std::endl;
        break;
    }
  }
  std::cout << "The experiment is over" << std::endl;
  return 0;
}
