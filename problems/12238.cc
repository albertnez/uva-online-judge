#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;
typedef long long ll;

const int maxn = 100005;
const int maxp = 18;

MI G;
int sp[maxn*2][maxp];
int when[maxn];
int who[maxn*2], depth[maxn*2];
ll dist[maxn];
int act;

void dfs(int u, int pre, int d) {
  when[u] = act;
  who[act] = u;
  depth[act] = d;
  ++act;
  for (int v : G[u]) {
    if (v != pre) {
      dfs(v, u, d+1);
      who[act] = u;
      depth[act] = d;
      ++act;
    }
  }
}

//LCA of nodes A and B
int lca(int a, int b) {
  a = when[a];
  b = when[b];
  if (a > b) swap(a,b);
  int p = log2(b-a+1);
  int ia = sp[a][p];
  int ib = sp[b-(1<<p)+1][p];
  int ans = (depth[ia] < depth[ib] ? ia : ib);
  return who[ans];
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  while (cin >> n and n) {
    act = 0;
    G = MI(n);
    memset(dist, 0, sizeof dist);
    for (int b = 1; b <= n-1; ++b) {
      int a, c;
      cin >> a >> c;
      dist[b] = dist[a] + c;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    dfs(0, -1, 0);

    for (int i = 0; i < n*2; ++i) sp[i][0] = i;
    for (int j = 1; (1<<j) <= n*2; ++j) {
      for (int i = 0; i + (1<<j) <= n*2; ++i) {
        int ia = sp[i][j-1], ib = sp[i+(1<<(j-1))][j-1];
        if (depth[ia] < depth[ib]) sp[i][j] = ia;
        else sp[i][j] = ib;
      }
    }
    int q;
    cin >> q;
    while (q--) {
      int a, b;
      cin >> a >> b;
      if (a == b) {
        cout << 0 << (q?" ":"");
      }
      else {
        int c = lca(a,b);
        //cout << " c: " << c << endl;
        cout << dist[a] + dist[b] - 2LL*dist[c] << (q?" ":"");
      }
    }
    cout << "\n";
  }
}

