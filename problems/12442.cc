#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vi;


Vi targ, dist;

int loopd = 0;
int endloop = -1;
void f(int u, int st) {
  if (dist[u] == 0) {
    dist[u] = -st;
    f(targ[u], st+1);
  }
  else if (dist[u] < 0) {
    loopd = st+dist[u];
    endloop = u;
    return;
  }
  
  if (loopd) {
    dist[u] = loopd;
    if (endloop == u) loopd = 0;
  }
  else {
    dist[u] = dist[targ[u]]+1;
  }
}

int main() {
  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    int n; cin >> n;
    targ.assign(n, 0);
    dist.assign(n, 0);
    for (int i = 0; i < n; ++i) {
      int a, b; 
      cin >> a >> b;
      targ[a-1] = b-1;
    }
    
    int sol = 0;
    int best = 0;
    for (int i = 0; i < n; ++i) {
      if (!dist[i]) {
        f(i, 1);
      }
      if (dist[i] > best) {
        best = dist[i];
        sol = i;
      }
    }
    cout << "Case " << ++ncase << ": " << sol+1 << endl;
  }
}