#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;

const int inf = 1e9;


int main() {
  int n;
  while (cin >> n and n != -1) {
    MI G(n);
    VI wts(n);
    vector<vector<int> > reach(n, vector<int> (n, false));
    for (int i = 0; i < n; ++i) {
      int m;
      cin >> wts[i] >> m;
      for (int j = 0; j < m; ++j) {
        int x; cin >> x;
        --x;
        G[i].push_back(x);
        reach[i][x] = true;
      }
    }

    
    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          reach[i][j] |= (reach[i][k] and reach[k][j]);
    
    VI dist(n, -inf);
    dist[0] = 100;

    for (int i = 0; i < n-1; ++i) {
      for (int u = 0; u < n; ++u) {
        for (int k = 0; k < int(G[u].size()); ++k) {
          int v = G[u][k];
          if (dist[u] + wts[v] > dist[v] and dist[u]+wts[v] > 0) {
            dist[v] = dist[u] + wts[v];
          }
        }
      }
    }
    //check if cycle
    bool possible = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < int(G[i].size()); ++j) {
        int v = G[i][j];
        if (dist[i]+wts[v] > 0 and dist[i]+wts[v] > dist[v] and reach[v][n-1])
          possible = true;
      }
    }
    possible |= (dist[n-1] > 0);
    if (possible) cout << "winnable" << endl;
    else cout << "hopeless" << endl;
  }
  
}