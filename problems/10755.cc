#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> MI;
typedef vector<MI> TI;
int main() {
  int T; cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    TI map(a, MI(b, VI(c)));
    for (int k = 0; k < a; ++k) for (int i = 0; i < b; ++i) for (int j = 0; j < c; ++j) {
      cin >> map[k][i][j];
      if (i > 0) map[k][i][j] += map[k][i-1][j];
      if (j > 0) map[k][i][j] += map[k][i][j-1];
      if (i > 0 and j > 0) map[k][i][j] -= map[k][i-1][j-1];
    }
    
    ll maxim = map[0][0][0];
    for (int i = 0; i < b; ++i) for (int j = 0; j < c; ++j)
    for (int k = i; k < b; ++k) for (int l = j; l < c; ++l) {
      ll sum = 0;
      for (int n = 0; n < a; ++n) {
        ll t = map[n][k][l];
        if (i > 0) t -= map[n][i-1][l];
        if (j > 0) t -= map[n][k][j-1];
        if (i > 0 and j > 0) t += map[n][i-1][j-1];
        sum = max(t, sum+t);
        maxim = max(maxim, sum);
      }
    }
    cout << maxim << endl;
    if (T) cout << endl;
  }
}