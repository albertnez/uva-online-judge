#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;


vector<bool> vis;
Mi g, r;
Vi topo, paths, deaths;

void dfs(int u) {
  vis[u] = true;
  for (int i = 0; i < g[u].size(); ++i) {
    if (!vis[g[u][i]])
      dfs(g[u][i]);
  }
  topo.push_back(u);
}

int main() {
  int n;
  bool first = true;
  while (cin >> n) {
    if (first) first = false;
    else cout << endl;
    g = r = Mi(n);
    topo.assign(0, 0);
    deaths.assign(0, 0);
    vis.assign(n, false);
    paths.assign(n, 0);
    paths[0] = 1;
    for (int i = 0; i < n; ++i) {
      int m; cin >> m;
      if (!m) deaths.push_back(i);
      while (m--) {
        int k; cin >> k;
        g[i].push_back(k);
        r[k].push_back(i);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (!vis[i])
        dfs(i);
    }
    for (int i = n-1; i >= 0; --i) {
      int u = topo[i];
      for (int j = 0; j < r[u].size(); ++j) {
        paths[u] += paths[r[u][j]];
      }
    }
    int ans = 0;
    for (int i = 0; i < deaths.size(); ++i)
      ans += paths[deaths[i]];
    cout << ans << endl;
  }
}