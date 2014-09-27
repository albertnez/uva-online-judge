#include <iostream>
#include <set>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m and (n|m)) {
    int t = 0;
    set<int> ms;
    for (int i = 0; i < n; ++i) {
      int k; cin >> k;
      ms.insert(k);
    }
    for (int i = 0; i < m; ++i) {
      int k; cin >> k;
      t += ms.count(k);
    }
    cout << t << endl;
  }
}