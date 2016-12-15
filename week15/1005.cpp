#include <iostream>
#include <list>
using namespace std;
#define MAX 13

inline int hash_fun(int key) {
    return key % MAX;
}

int main() {
    int n;
    while (1) {
        cin >> n;
        if (n == 0) break;
        list<int> hash_table[MAX];
        while (n--) {
            int key;
            cin >> key;
            int index = hash_fun(key);
            hash_table[index].push_back(key);
        }
        for (int i = 0; i < MAX; ++i) {
            cout << i << "#";
            if (hash_table[i].empty()) {
                cout << "NULL" << endl;
            } else {
                for (list<int>::const_iterator iter = hash_table[i].begin(); iter != hash_table[i].end(); ++iter) {
                    if (iter != hash_table[i].begin()) {
                        cout << " ";
                    }
                    cout << *iter;
                }
                cout << endl;
            }
        }
    }
    return 0;
}
