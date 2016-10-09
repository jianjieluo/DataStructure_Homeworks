#include <iostream>
#include <stack>
#include <vector>

/**
 * To display the correct result
 * @param result the vector that store the correct answer
 */
inline void display(const std::vector<int>& result) {
  for (const auto& per : result) {
    std::cout << per << " ";
  }
  std::cout << std::endl;
}

/**
 * a rescusive function to solve the package problem
 * @param ptotal the previous weight the package has taken in
 * @param T      the standard weight
 * @param index  the position that the current thing that is going to be put in
 * the package
 * @param vec    a vector stored all the things that can be put into the package
 * @param result a vector to store the things that have been put into the
 * package
 */
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
    }
    result.pop_back();
    put(ptotal, T, index + 1, vec, result);
  }
}

int main(int argc, char const* argv[]) {
  int T, temp;
  std::cin >> T;

  // initialize the original things that can be put into the package
  std::vector<int> vec;
  std::cout << "Please end the input using EOF" << std::endl;
  while (std::cin >> temp) {
    vec.push_back(temp);
  }

  std::cout << "The correct results can be listed below" << std::endl;
  std::vector<int> res;
  put(0, T, 0, vec, res);

  return 0;
}
