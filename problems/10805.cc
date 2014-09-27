#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;

const int inf = 1e9;

int main() {
  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    int n, m;
    cin >> n >> m;
    
    int t = n+m;
    MI adj(t, VI(t, inf));
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      adj[a][n+i] = adj[n+i][a] = adj[b][n+i] = adj[n+i][b] = 1;
    }
    
    for (int k = 0; k < t; ++k) 
      for (int i = 0; i < t; ++i)
        for (int j = 0; j < t; ++j)
          adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
      
    int ans = inf;
    for (int i = 0; i < t; ++i) {
      int mx1 = 0, mx2 = 0;
      for (int j = 0; j < n; ++j) {
        if (adj[i][j] > mx1) {
          mx2 = mx1;
          mx1 = adj[i][j];
        }
        else if (adj[i][j] > mx2) {
          mx2 = adj[i][j];
        }
      }
      ans = min(ans, mx1+mx2);
    }
    cout << "Case #" << ++ncase << ":" << endl;
    cout << ans/2 << endl << endl;
  }
}
