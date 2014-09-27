#include <iostream>
using namespace std;

int main() {
  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    int n;
    cin >> n;
    int sol = 0;
    while (n--) {
      int k; cin >> k;
      sol = max(sol, k);
    }
    cout << "Case " << ++ncase << ": " << sol << endl;
  }
}