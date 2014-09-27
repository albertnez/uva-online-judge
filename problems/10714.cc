#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int T; cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int l = 0, h = 0;
    while (m--) {
      int k; cin >> k;
      l = max(l, min(k, n-k));
      h = max(h, max(k, n-k));
    }
    cout << l << ' ' << h << endl;
  }
}