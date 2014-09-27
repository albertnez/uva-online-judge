#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int exp(int b, int e, int mod) {
  if (e == 0) return 1;
  if (e == 1) return b;
  int m = exp(b, e/2, mod);
  m = (m*m)%mod;
  if (e&1) m = (m*b)%mod;
  return m;
}

int main() {
  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    int n, k, mod;
    cin >> n >> k >> mod;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      v[i] %= mod;
    }
    
    int mult = exp(n, k-1, mod);
    mult = (ll(mult)*ll(k))%ll(mod);
    
    int ans = 0;
    for (int i = 0; i < n; ++i)
      ans = (ans + mult*v[i])%mod;
    
    cout << "Case " << ++ncase << ": " << ans << endl;
  }
}