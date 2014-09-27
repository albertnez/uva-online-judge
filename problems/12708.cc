#include <iostream>
typedef long long ll;
using namespace std;
int main() {
  int T; cin >> T;
  while (T--) {
    ll n; cin >> n;
    if (n&1) --n;
    if (n > 1) cout << n/2 << endl;
    else cout << 1 << endl;
  }
}