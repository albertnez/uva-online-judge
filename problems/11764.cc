#include <iostream>
using namespace std;
int main() {
  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    int n; cin >> n;
    int k; cin >> k;
    int high = 0, low = 0;
    while (--n) {
      int t; cin >> t;
      if (t > k) ++high;
      if (t < k) ++low;
      k = t;
    }
    cout << "Case " << ++ncase << ": " << high << ' ' << low << endl;
  }
}