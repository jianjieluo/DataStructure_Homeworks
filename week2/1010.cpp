#include <iostream>

int main() {
    int a[10] = {};
    for (int i = 0; i < 10; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 9; j > i; --j) {
            if (a[j] < a[j-1]) {
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
    }

    for (int i = 0; i < 10; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
