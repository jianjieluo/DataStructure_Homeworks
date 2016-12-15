#include <cstdio>
#include <cstdlib>
#define MAX 10000000
using namespace std;

int a[MAX] = {0};
bool flag[MAX] = {false};

void swap(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int partition(int lhs, int n) {
    int i = lhs-1;
    for (int j = lhs; j < lhs+n; ++j) {
        if (a[j] < a[lhs+n-1]) {
            swap(a[++i], a[j]); 
        }
    }
    swap(a[++i], a[lhs+n-1]);
    return i;
}

int getMaxK(int lhs, int n, int k) {
    int mid = partition(lhs, n);
    if (mid == n-k)
        return a[mid];
    else if (mid < n-k)
        return getMaxK(lhs+mid+1, n-mid-1, k);
    else 
        return getMaxK(lhs, mid, k-n+mid);
}


int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int size = 0;
    while(n--) {
        int temp;
        scanf("%d", &temp);
        if (!flag[temp]) {
            a[size++] = temp;
            flag[temp] = true;
        }
    }
    // cout << getMaxK(p, size, k)<<endl;
    if (k-1 >= 0 && k-1 < size) {
      printf("%d\n", getMaxK(0, size, k));
    }
    return 0;
}