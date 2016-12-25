// #include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  set<int> s;
  while (n--) {
    int temp;
    cin >> temp;

    s.insert(temp);
  }
  set<int>::reverse_iterator it1;
  it1 = s.rbegin();
  while (--k) {
    ++it1;
  }
  cout << *it1 << endl;
  return 0;
}
