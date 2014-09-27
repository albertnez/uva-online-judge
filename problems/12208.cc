#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll bits(ll n) {
  ll t = 0;
  ll add = 1, rng = 2;
  while (add <= n) {
    ll x = n - add+1;
    t += add*(x/rng) + min(x%rng,add);
    add <<= 1;
    rng <<= 1;
  }
  return t;
}

int main() {
  int a, b;
  int ncase = 0;
  while (cin >> a >> b and (a|b))
    cout << "Case " << ++ncase << ": " << bits(b)-bits(max(a-1,0)) << endl;
  
}