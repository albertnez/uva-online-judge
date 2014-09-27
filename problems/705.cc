#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> II;
typedef vector<II> VII;
typedef vector<VII> MII;
typedef vector<MII> TII;
typedef vector<int> VI;
typedef vector<VI> MI;

MII vis;
TII G;
int dfs(int r, int c) {
  int ans = -1;
  for (int i = 0; i < int(G[r][c].size()); ++i) {
    int ni = G[r][c][i].first, nj = G[r][c][i].second;
    if (vis[ni][nj] == II(-1,-1)) {
      vis[r][c] = II(ni,nj);
      int tmp = dfs(ni, nj);
      if (tmp >= 0) ans = max(ans, tmp+1);
    }
    else if (vis[ni][nj] != II(r,c)) return 1;
  }
  return ans;
}

int main() {
  int n, m;
  int ncase = 0;
  while (cin >> m >> n and (n|m)) {
    G = TII(2*n+1, MII(m+1));
    vis = MII(2*n+1, VII(m+1, II(-1,-1)));
    //Build graph
    for (int i = 1; i < n*2; i+=2) {
      for (int j = 0; j < m; ++j) {
        char c; cin >> c;
        if (c == '/') {
          G[i-1][j].push_back(II(i, j));
          G[i][j].push_back(II(i-1, j));
        
          G[i][j+1].push_back(II(i+1,j));
          G[i+1][j].push_back(II(i,j+1));
      }
      else { // we have '\'
          G[i-1][j].push_back(II(i,j+1));
          G[i][j+1].push_back(II(i-1,j));
        
          G[i][j].push_back(II(i+1,j));
          G[i+1][j].push_back(II(i,j));
        }
      }
    }
    int ncycles = 0;
    int maxcycle = 0;
    for (int i = 0; i < n*2; ++i) {
      for (int j = 0; j < m; ++j) {
        if (vis[i][j] == II(-1,-1)) {
          int tmp = dfs(i, j);
          if (tmp > 0) {
            ++ncycles;
            maxcycle = max(maxcycle, tmp);
          }
        }
      }
    }
    
    cout << "Maze #" << ++ncase << ":" << endl;
    if (ncycles) cout << ncycles << " Cycles; the longest has length " << maxcycle << "." << endl;
    else cout << "There are no cycles." << endl;
    cout << endl;
  }
}