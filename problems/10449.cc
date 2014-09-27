#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;
typedef pair<int,int> II;
typedef vector<II> VII;
typedef vector<VII> MII;
const int inf = 1e9;
int main() {
  int n;
  int ncase = 0;
  while (cin >> n) {
    VI vw(n);
    for (int i = 0; i < n; ++i)
      cin >> vw[i];
    
    MII G(n);
    MI reach(n, VI(n, 0));
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      int d = vw[b]-vw[a];
      G[a].push_back(II(b, d*d*d));
      reach[a][b] = true;
    }
    
    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          reach[i][j] |= (reach[i][k] and reach[k][j]);
    
    VI dist(n, inf);
    dist[0] = 0;
    for (int k = 0; k < n-1; ++k)
      for (int i = 0; i < n; ++i) if (dist[i] < inf)
        for (int j = 0; j < int(G[i].size()); ++j) {
          int v = G[i][j].first;
          int w = G[i][j].second;
          dist[v] = min(dist[v], dist[i]+w);
        }
    //check
    VI cycle(n, 0);
    
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < int(G[i].size()); ++j) {
        int v = G[i][j].first;
        int w = G[i][j].second;
        if (dist[i] < inf and dist[i]+w < dist[v]) {
          cycle[v] = true;
          cycle[i] = true;
          for (int k = 0; k < n; ++k)
            if (reach[v][k])
              cycle[k] = true;
        }
      }
    
    cout << "Set #" << ++ncase << endl;
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
      int k;
      cin >> k;
      --k;
      if (k < 0 or k >= n or dist[k] < 3 or cycle[k] or dist[k] == inf) cout << "?" << endl;
      else cout << dist[k] << endl;
    }
  }
}