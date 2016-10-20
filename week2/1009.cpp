// the code is solve the 约瑟夫问题
// 也就是循环报数，使用循环链表来模拟

#include <iostream>

struct Node {
  int data;
  Node* next;
  Node(int _data, Node* _next) : data(_data), next(_next) {}
};

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, m;
    std::cin >> n >> m;

    if (m == 1) {
      std::cout << n << std::endl;
      continue;
    }

    Node* head = NULL;
    Node* ptr = NULL;
    head = new Node(0, NULL);
    ptr = head;
    for (int i = 1; i <= n; ++i) {
      Node* temp = new Node(i, NULL);
      ptr->next = temp;
      ptr = temp;
      temp = NULL;
    }

    ptr->next = head->next;

    // begin to simulate
    ptr = head;

    while (ptr->next != ptr) {
      for (int i = 1; i < m; ++i) {
        ptr = ptr->next;
      }
      Node* temp = ptr->next;
      ptr->next = temp->next;
      delete temp;
    }
    std::cout << ptr->data << std::endl;
  }
  return 0;
}
