#include <iostream>
#include <stack>
#include <vector>

inline void display(const std::vector<int>& result) {
  for (const auto& per : result) {
    std::cout << per << " ";
  }
  std::cout << std::endl;
}

void put(int ptotal, const int T, unsigned int index,
         const std::vector<int>& vec, std::vector<int>& result) {
  if (index == vec.size()) {
    return;
  } else {
    result.push_back(vec[index]);
    int ctotal = ptotal + vec[index];
    if (ctotal < T) {
      put(ctotal, T, index + 1, vec, result);
    } else if (ctotal == T) {
      display(result);
    } else {
      result.pop_back();
      put(ptotal, T, index + 1, vec, result);
    }
  }
}

int main(int argc, char const* argv[]) {
  int T, temp;
  std::cin >> T;
  std::vector<int> vec;
  while (std::cin >> temp) {
    vec.push_back(temp);
  }
  for (unsigned int i = 0; i < vec.size(); ++i) {
    std::vector<int> res;
    put(0, T, i, vec, res);
  }

  return 0;
}
