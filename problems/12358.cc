#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  while (b) {
    ll r = a%b;
    a = b;
    b = r;
  }
  return a;
}

int f;
ll g, sum;
vector<int> c;
ll ans;

ll group(ll s) {
  if (s < 2) return 0;
  if (sum%s != 0) return 0;
  ll minim = 1LL<<62;
  ll mod = (c[0] - s - s/f)%s;
//   cout << "with s = " << s << " mod = " << mod << endl;
  for (int i = 0; i < f; ++i) {
    ll r = c[i] -s - s/f;
    if (r < 0 or r%s != mod) return 0;
    minim = min(minim, r);
  }
  return minim/s+1;
}

int main() {
  ios_base::sync_with_stdio(false);
  while (cin >> f and f) {
    c.assign(f, 0);
    for (int i = 0; i < f; ++i)
      cin >> c[i];
    
    g = sum = 0;
    for (int i = 0; i < f; ++i) {
      g = gcd(g, c[i]);
      sum += c[i];
    }
    
    ans = 0;
    if (sum%f == 0) {
      for (ll d = 1; d*d <= g; ++d) {
        if (g%d == 0) {
          ans += group(d*f);
          if (g/d != d) ans += group(g/d*f);
        }
      }
    }
    
    cout << ans << endl;
  }
}