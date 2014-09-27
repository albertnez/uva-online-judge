#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;

int dfsc = 0;
int ncc;
Vi low, num, parent, p;
Vi vis;
Mi g, h;


int getp(int u) {
  if (p[u] == u) return u;
  else return (p[u] = getp(p[u]));
}

bool same(int u, int v) {
  return getp(u) == getp(v);
}

void joinset(int u, int v) {
  if (same(u, v)) return;
  p[getp(u)] = getp(v);
}

void join(int a, int b) {
  h[a].push_back(b);
  h[b].push_back(a);
}

void bridge(int u) {
  low[u] = num[u] = dfsc++;
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (num[v] == -1) {
      parent[v] = u;
      
      bridge(v);
      
      if (low[v] > num[u]) {
	join(u, v);
      }
      
      low[u] = min(low[u], low[v]);
    }
    else if (v != parent[u])
      low[u] = min(low[u], num[v]);
  }
}

void dfs(int u) {
  vis[u] = ncc;
  for (int i = 0; i < h[u].size(); ++i) {
    int v = h[u][i];
    if (!vis[v]) dfs(v);
  }
}

int main() {
  int n, m, q;
  while (cin >> n >> m >> q and (n|m|q)) {
    g = h = Mi(n);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    
    dfsc = 0;
    num = Vi(n, -1);
    low = parent = Vi(n, 0);
    
    
    for (int i = 0; i < n; ++i) {
      if (num[i] == -1) {
	bridge(i);
      }
    }
    
    
    
    vis = Vi(n, 0);
    for (int i = 0; i < n; ++i) {
      ++ncc;
      if (!vis[i]) {
	dfs(i);
      }
    }
    
    while (q--) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      if (vis[a] == vis[b]) cout << "Y" << endl;
      else cout << "N" << endl;
    }
    cout << "-" << endl;
    
  }  
}