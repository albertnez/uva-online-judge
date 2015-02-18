#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> MI;

const int maxn = 10000;
const int maxm = 50;

int memo[maxn+5][maxm+5];
int hmemo[maxn+5][maxm+5];
int L[maxn+5], R[maxn+5];
int divs[maxn+5][maxm+5];

int gcd(int a, int b) {
  if (a%b == 0) return b;
  return gcd(b, a%b);
}

MI G;
MI Aux;
int N;
const int mod = 21092013;
int ncase = 0;

void generate(int u, int p) {
  for (int x : Aux[u]) {
    if (x != p) {
      G[u].push_back(x);
      generate(x, u);
    }
  }
}

// number of paths starting at u
int f(int u, int m) {
  int& ans = memo[u][m];
  if (ans != -1) return ans;
  ans = divs[u][m];

  for (int v : G[u]) {
    ll s = ll(f(v,m)) * ll(divs[u][m]);
    if (s >= mod) s %= mod;
    ans += s;
    if (ans >= mod) ans %= mod;
  }

  return ans;
}

// Total Number of paths from u
int h(int u, int m) {
  int& ans = hmemo[u][m];
  if (ans != -1) return ans;

  // Paths starting at u
  ans = f(u, m);

  // Sum of paths starting in one son
  ll sum = 0;
  // Paths not starting at u
  for (int v : G[u]) {
    // Adding paths from v
    ans += h(v, m);
    if ( ans >= mod) ans %= mod;
    // adding paths that don't start at u, but go through u
    ll t = sum * ll(f(v, m)) * ll(divs[u][m]);
    if (t >= mod) t %= mod;
    ans += t;
    if ( ans >= mod) ans %= mod;
    sum += f(v, m);
    if (sum >= mod) sum %= mod;
  }

  return ans;
}

int main() {
  int T; cin >> T;
  while (T--) {
    cin >> N;
    Aux = G = MI(N);
    for (int i = 0; i < N-1; ++i) {
      int u, v; cin >> u >> v; --u; --v;
      Aux[u].push_back(v);
      Aux[v].push_back(u);
    }
    generate(0, 0);

    for (int i = 0; i < N; ++i) cin >> L[i];
    for (int i = 0; i < N; ++i) cin >> R[i];

    // calc divs
    for (int i = 0; i < N; ++i) {
      for (int m = 1; m <= maxm; ++m) {
        divs[i][m] = 0;
        for (int k = m; k <= maxm && k <= R[i]; k += m) {
          if (k >= L[i] && k <= R[i]) ++divs[i][m];
        }
      }
    }
          
    cout << "Case " << ++ncase << ":" << '\n';
    // calc everytthing
    memset(memo, -1, sizeof memo);
    memset(hmemo, -1, sizeof hmemo);
    for (int m = 1; m <= maxm; ++m) h(0, m);

    // inclusion exclusion
    for (int m = 1; m <= maxm; ++m) {
      vector<int> mult(maxm+1, 0);
      int ans = h(0, m);
      for (int k = m; k <= maxm; k += m) ++mult[k];
      for (int k = 2*m; k <= maxm; k+=m) {
        int x = mult[k]*-1;
        if (x) {
          ans += ll(ll(h(0, k))*ll(x))%mod;
          for (int q = k; q <= maxm; q += k) mult[q] += x;
          if (ans < 0) ans += mod;
          if (ans >= mod) ans %= mod;
        }
      }
      cout << m << ": " << ans << '\n';
    }

  }

}
