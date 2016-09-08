#include <cstring>
#include <iostream>

bool judge() {
  int n;
  std::cout << "Please input the square size." << std::endl;
  std::cin >> n;
  std::cout << "Please input the square." << std::endl;
  int** square = new int*[n];
  for (int i = 0; i < n; ++i) {
    square[i] = new int[n];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> square[i][j];
    }
  }

  int standard = 0;
  for (int i = 0; i < n; ++i) {
    standard += square[0][i];
  }

  for (int i = 0; i < n; ++i) {
    int temp = 0;
    for (int j = 0; j < n; ++j) {
      temp += square[i][j];
    }
    if (temp != standard) return false;
  }
  for (int i = 0; i < n; ++i) {
    int temp = 0;
    for (int j = 0; j < n; ++j) {
      temp += square[j][i];
    }
    if (temp != standard) return false;
  }
  int temp = 0;
  for (int i = 0; i < n; ++i) {
    temp += square[i][i];
  }
  if (temp != standard) return false;
  temp = 0;
  for (int i = n - 1; i >= 0; --i) {
    temp += square[i][i];
  }
  if (temp != standard) return false;

  for (int i = 0; i < n; ++i) {
    delete[] square[i];
  }
  delete[] square;
  return true;
}

void construct() {
  int n;
  std::cin >> n;
  if (!(n % 2)) return;
  int size = n * n;
  int* a = new int[size];
  memset(a, 0, size);
  auto element = [a, n](int x, int y) -> int& { return a[x * n + y]; };

  int x = 0;
  int y = (n - 1) / 2;
  int new_x, new_y;

  for (int val = 1; val <= size; ++val) {
    element(x, y) = val;

    new_y = (y + 1) % n;
    if (x - 1 < 0)
      new_x = (x - 1 + n) % n;
    else
      new_x = x - 1;

    if (element(new_x, new_y) == 0) {
      x = new_x;
      y = new_y;
    } else {
      ++x;
    }

    // Another very easy judgement but I can't find it by myself
    // if (val % n == 0) {
    //   x += 2;
    //   --y;
    // } else {
    //   if (y == n)
    //     y -= n;
    //   else if (x < 0)
    //     x += n;
    // }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << element(i, j) << "\t";
    }
    std::cout << std::endl;
  }

  delete[] a;
}

int main() {
  std::cout << "input 1 for judge and 2 for construct" << std::endl;
  int choice;
  std::cin >> choice;
  if (choice == 1)
    if (judge())
      std::cout << "Yes" << std::endl;
    else
      std::cout << "No" << std::endl;
  else if (choice == 2)
    construct();
  return 0;
}
