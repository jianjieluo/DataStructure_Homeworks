#include <deque>
#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  int t;
  std::cin >> t;
  std::deque<int> cards;
  while (t--) {
    cards.clear();
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
      cards.push_back(i);
    }

    // begin to play
    while (cards.size() >= 2) {
      std::cout << cards.front() << " ";
      cards.pop_front();
      cards.push_back(cards.front());
      cards.pop_front();
    }

    std::cout << cards.front() << " " << std::endl;
  }
  return 0;
}
