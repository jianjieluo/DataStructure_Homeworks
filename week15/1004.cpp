#include <stdio.h>
#define MAX 10000000
using namespace std;

bool flag[MAX] = {false};
int a[MAX] = {0};

void swap(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int partition(int lhs, int rhs) {
    int i = lhs - 1;
    for (int j = lhs; j < rhs; j++) {
        if (a[j] > a[rhs]) {
            swap(a[++i], a[j]);
        }
    }
    swap(a[++i], a[rhs]);
    return i;
}

void quick_sort(int p, int r) {
    if (p < r) {
        int q = partition(p, r);
        quick_sort(p, q - 1);
        quick_sort(q + 1, r);
    }
}

int main() { 
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    int size = 0;
    while (n--) {
      int num;
      scanf("%d", &num);
      if (flag[num] == false) {
        a[size++] = num;
        flag[num] = true;
      }
    }
    quick_sort(0, size-1);
    if (k-1 >= 0 && k-1 < size) {
      printf("%d\n", a[k-1]);
    }
    return 0;
}