#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  int T; cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    int x = 0;
    for (int i = 0; i < n; ++i) {
      ll p = (1<<(i+2));
      x |= (((k+(p-(1<<i)))%p) < p/2)<<i;
    }
    cout << x << endl;
  }
}