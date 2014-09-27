#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<ll> VLL;
int N;
int total = 0;
int maxim = 0;
VLL G;
void bt(int i, ll state, int depth) {
  if (i == N) {
    if (state == (1LL<<N)-1) {
      ++total;
      maxim = max(maxim, depth);
    }
  }
  else {
    if (!(state&(1LL<<i))) {
      bt(i+1, state | G[i], depth+1);
    }
    bt(i+1, state, depth);
  }
}

int main() {
  int T; cin >> T;
  while (T--) {
    total = maxim = 0;
    int r;
    cin >> N >> r;
   
    G = VLL(N, 0);
    for (int i = 0; i < N; ++i) G[i] |= (1LL<<i);
    while (r--) {
      int a, b;
      cin >> a >> b;
      G[a] |= (1LL<<b);
      G[b] |= (1LL<<a);
    }
    bt(0, 0, 0);
    cout << total << endl << maxim << endl;
  }
}
