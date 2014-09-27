#include <iostream>
using namespace std;

int main() {
  int n, m, c;
  while (cin >> n >> m >> c and (n|m|c)) {
    n -= 7;
    m -= 7;
    int ans;
    if (c) {
      ans = ((n+1)/2)*((m+1)/2) + ((n)/2)*((m)/2);
    }
    else {
      ans = ((n+1)/2)*((m)/2) + ((n)/2)*((m+1)/2);
    }
    cout << ans << endl;
  }
}