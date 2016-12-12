#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
  int T;
  std::cin >> T;
  set<int> a, b;
  while (T--) {
    vector<int> output(100000);
    int n;
    cin >> n;
    while (n--) {
      int temp;
      cin >> temp;
      a.insert(temp);
    }
    int m;
    cin >> m;
    while (m--) {
      int temp;
      cin >> temp;
      b.insert(temp);
    }
    vector<int>::iterator it;
    it = set_difference(a.begin(), a.end(), b.begin(), b.end(), output.begin());
    output.resize(it - output.begin());
    sort(output.begin(), output.end());
    for (vector<int>::iterator iter = output.begin(); iter != output.end();
         ++iter) {
      if (iter != output.begin()) {
        cout << " ";
      }
      cout << *iter;
    }
    cout << endl;
    a.clear();
    b.clear();
    output.clear();
  }
  return 0;
}
