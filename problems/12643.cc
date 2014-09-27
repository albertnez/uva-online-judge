#include <iostream>
using namespace std;

int main() {
  int n, a, b;
  while (cin >> n >> a >> b) {
    --a; --b;
    int ans = 0;
    while (a != b) {
      a >>= 1;
      b >>= 1;
      ++ans;
    }
    cout << ans << endl;
  }
}