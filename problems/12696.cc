#include <iostream>
using namespace std;


const double maxl = 56, maxw = 45, maxd = 25, maxp = 7, maxs = 125;

int main() {
  int T; cin >> T;
  int total = 0;
  while (T--) {
    double l, w, h, p;
    cin >> l >> w >> h >> p;
    if (((l <= maxl and w <= maxw and h <= maxd) or l+w+h <= maxs) and p <= maxp) {
      ++total;
      cout << 1 << endl;
    }
    else {
      cout << 0 << endl;
    }
  }
  cout << total << endl;
}