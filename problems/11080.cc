#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;

MI G;
VI color;
int bfs(int u) {
  queue<int> q;
  q.push(u);
  color[u] = 0;
  VI cost(2, 0);
  cost[0] = 1;
  
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (int i = 0; i < int(G[u].size()); ++i) {
      int v = G[u][i];
      if (color[v] == -1) {
        color[v] = 1-color[u];
        ++cost[color[v]];
        q.push(v);
      }
      else if (color[v] == color[u]) {
        return -1;
      }
    }
  }
  return max(min(cost[0], cost[1]), 1);
}

int main() {
  int T; cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    G = MI(n);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    color = VI(n, -1);
    
    int ans = 0;
    for (int i = 0; i < n and ans != -1; ++i) {
      if (color[i] == -1) {
        int k = bfs(i);
        if (k == -1) ans = k;
        else ans += k;
      }
    }
    cout << ans << endl;
  }
} 