#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Vi;
typedef vector<Vi> Mi;

const int mod = 1000007;

int main() {
  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    int n;
    cin >> n;
    Mi m(n, Vi(n, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        char c; cin >> c;
        if (c == 'B') m[i][j] = -1;
        else if (c == 'W') m[i][j] = 1;
      }
    }
  
    for (int i = n-1; i > 0; --i) {
      for (int j = 0; j < n; ++j) if (m[i][j] >= 0) {
        int ti = i-1;
        if (j-1 >= 0) {
          int tj = j-1;
          if (m[ti][tj] >= 0) m[ti][tj] = (m[i][j] + m[ti][tj])%mod;
          else if (tj-1 >= 0 and ti-1 >= 0 and m[ti-1][tj-1] >= 0) m[ti-1][tj-1] = (m[i][j] + m[ti-1][tj-1])%mod;
        }
        if (j+1 < n) {
          int tj = j+1;
          if (m[ti][tj] >= 0) m[ti][tj] = (m[i][j] + m[ti][tj])%mod;
          else if (tj+1 < n and ti-1 >= 0 and m[ti-1][tj+1] >= 0) m[ti-1][tj+1] = (m[i][j] + m[ti-1][tj+1])%mod;
        }
      }
    }
    int ans = 0;
    for (int j = 0; j < n; ++j) 
      if (m[0][j] >= 0) ans = (ans + m[0][j])%mod;

    cout << "Case " << ++ncase << ": " << ans << endl;
  }
}