#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;

const int n = 27;

Vi topo;
Mi g;
vector<bool> vis;

void dfs(int u) {
   vis[u] = true;
   for (int i = 0; i < g[u].size(); ++i) {
     if (!vis[g[u][i]])
       dfs(g[u][i]);
   }
   topo.push_back(u);
}

void topof() {
  vis.assign(n, false);
  topo.assign(0,0);
  for (int i = 0; i < n; ++i)
    if (!vis[i])
      dfs(i);
}

int main() {
  int T; cin >> T;
  cin.ignore();
  cin.ignore();
  while (T--) {
    string s;
    
    Vi wts(n, 0);
    Vi act(n, 0);
    Vi ind(n, 0);
    int maxind = 0;
    g = Mi(n);
    
    while (getline(cin,s) and s != "") {
      istringstream ss(s);
      char c; ss >> c;
      int st = c-'A';
      int weight; ss >> weight;
      wts[st] = weight;
      while (ss >> c) {
        int to = c-'A';
        g[to].push_back(st);
        ++ind[st];
        maxind = max(maxind, ind[st]);
      }
    }
    topof();
  
    for (int i = n-1; i >= 0; --i) {
      int u = topo[i];
      act[u] -= wts[u];
      for (int j = 0; j < g[u].size(); ++j) {
        int v = g[u][j];
        act[v] = min(act[v], act[u]);
      }
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) 
        ans = min(ans, act[i]);
    
    
    cout << -ans << endl;
    if (T) cout << endl;
  }
}