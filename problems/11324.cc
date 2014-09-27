#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;
typedef vector<bool> VB;
typedef vector<VB> MB;

const int inf = 1e9;

MI G;
MB adj;
stack<int> S;

VI low;
VI num;
vector<bool> vis;
int id;

VI dag; //converted graph
VI dagSize;
int nscc;

MI H;

VI vtopo;
VI path;

void ftopo(int u) {
  vis[u] = true;
  for (int i = 0; i < int(H[u].size()); ++i) {
    int v = H[u][i];
    if (!vis[v]) ftopo(v);
  }
  vtopo.push_back(u);
}

void scc(int u) {
  vis[u] = true;
  num[u] = low[u] = ++id;
  
  S.push(u);
  
  for (int i = 0; i < int(G[u].size()); ++i) {
    int v = G[u][i];
    if (!num[v]) scc(v);
    if (vis[v]) low[u] = min(low[u], low[v]);
  }
  
  if (num[u] == low[u]) {
    dagSize.push_back(0);
    int v;
    do {
      v = S.top(); S.pop();
      vis[v] = false;
      dag[v] = nscc;
      ++dagSize[nscc];
    } while (v != u);
    
    ++nscc;
  }    
}

int main() {
  int T; cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    
    G = MI(n);
    adj = MB(n, VB(n, false));
    
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      if (!adj[a][b]) {
        adj[a][b] = true;
        G[a].push_back(b);
      }
    }
    
    low.assign(n, 0);
    num.assign(n, 0);
    vis.assign(n, false);
    id = 0;
    nscc = 0;
    dag.assign(n, 0);
    dagSize.assign(0,0);
    
    for (int i = 0; i < n; ++i) {
      if (!num[i]) scc(i);
    }
    
    //Build de DAG
    H = MI(nscc);
    adj = MB(nscc, VB(nscc, false));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < int(G[i].size()); ++j) {
        int u = G[i][j];
        int gi = dag[i], gu = dag[u];
        if (gi != gu and !adj[gi][gu]) {
          H[gi].push_back(gu);
          adj[gi][gu] = true;
        }
      }
    }
    
    vis.assign(nscc, false);
    path.assign(nscc, 0);
    vtopo.assign(0,0);
    for (int i = 0; i < nscc; ++i)
      if (!vis[i]) ftopo(i);
    
      
    int ans = 0;
    for (int i = nscc-1; i >= 0; --i) {
      path[i] += dagSize[i];
      ans = max(ans, path[i]);
      for (int j = 0; j < int(H[i].size()); ++j) {
        int v = H[i][j];
        path[v] = max(path[v], path[i]);
      }
    }
    
    cout << ans << endl;
  }
}