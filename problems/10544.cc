#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;

VI paths;
MI G;

void dfs(int u) {
  paths[u] = (G[u].size() == 0);
  for (int i = 0; i < int(G[u].size()); ++i) {
    int v = G[u][i];
    if (paths[v] == -1) dfs(v);
    paths[u] += paths[v];
  }
}

int main() {
  int T; cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    
    G = MI(n);
    vector<vector<bool> > adj(n, vector<bool>(n, false));
    paths.assign(n,-1);
    for (int i = 0; i < m; ++i) {
      char a,b; cin >> a >> b;
      int u = a-'A', v = b-'A';
      if (!adj[u][v]) {
        G[u].push_back(v);
        adj[u][v] = true;
      }
    }
    
    for (int i = 0; i < n; ++i) 
      sort(G[i].begin(), G[i].end());

    for (int i = 0; i < n; ++i)
      if (paths[i] == -1) dfs(i);
    
    int q;
    cin >> q;
        
    while (q--) {
      string s;
      cin >> s;
      int p = 0;
      int u = s[0]-'A';
      for (int i = 1; i < int(s.size()); ++i) {
        int v = s[i]-'A';
        int j = 0;
        while (G[u][j] != v) {
          p += paths[G[u][j]];
          ++j;
        }
        u = v;
      }
      cout << s << ": " << p+1 << endl;
    }
  }
}