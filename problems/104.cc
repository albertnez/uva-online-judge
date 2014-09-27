#include <iostream>
#include <vector>
using namespace std;
typedef vector<double> VD;
typedef vector<VD> MD;
typedef vector<MD> TD;
typedef vector<int> VI;
typedef vector<VI> MI;
typedef vector<MI> TI;

const int maxn = 21;

int main() {
  int n;
  while (cin >> n) {
    TD adj(n, MD(n, VD(maxn, 0.0)));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) adj[i][j][1] = 1.0;
        else cin >> adj[i][j][1];
      }
    }

    
    int found = -1;
    int st = 0;
    TI path(n, MI(n, VI(maxn, -1)));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        path[i][j][1] = j;
    
    
    for (int m = 2; m <= n and found == -1; ++m) {
      MI steps(n, VI(n, 1));
      for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        for (int it = 1; it < m; ++it) {
          double x = adj[i][k][it]*adj[k][j][m-it];
          if (x > adj[i][j][m]) {
            adj[i][j][m] = x;
            path[i][j][m] = path[i][k][it];
            if (i == j and x > 1.01) {
              found = i;
              st = m;
            }
          }
        }
      }
    }
    
    if (found != -1) {
      VI ans;
      int u = found, v = found;
      while (st >= 1) {
        ans.push_back(u+1);
        u = path[u][v][st];
        --st;
      }
      ans.push_back(v+1);
      for (int i = 0; i < int(ans.size()); ++i)
        cout << (i?" ":"") << ans[i];
      cout << endl;
    }
    else {
      cout << "no arbitrage sequence exists" << endl;
    }
  }
}