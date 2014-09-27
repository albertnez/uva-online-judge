#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef pair<int,int> ii;
typedef vector<ii> Vii;
typedef vector<Vii> Mii;
typedef pair<int, ii> ti;
const int INF = 1e9;

int main() {
  int T; cin >> T;
  while (T--) {
    int n, m, s, t, p;
    cin >> n >> m >> s >> t >> p;
    --s; --t;
    Mii g(n), rev(n);
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a; --b;
      g[a].push_back(ii(b, c));
      rev[b].push_back(ii(a,c));
    }
    
    // DIJKSTRA FROM S
    Vi dists(n, INF);
    dists[s] = 0;
    priority_queue<ii, Vii, greater<ii> > q;
    q.push(ii(0, s));
    
    while (!q.empty()) {
      int d = q.top().first;
      int u = q.top().second;
      q.pop();
      
      if (d > dists[u]) continue;
      for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i].first;
        int w = g[u][i].second;
        if (d+w < dists[v] and d+w <= p) {
          dists[v] = d+w;
          q.push(ii(d+w, v));
        }
      }
    }
    
        // DIJKSTRA FROM T
    Vi distt(n, INF);
    distt[t] = 0;
    q.push(ii(0, t));
    
    while (!q.empty()) {
      int d = q.top().first;
      int u = q.top().second;
      q.pop();
      
      if (d > distt[u]) continue;
      for (int i = 0; i < rev[u].size(); ++i) {        
        int v = rev[u][i].first;
        int w = rev[u][i].second;
        if (d+w < distt[v] and d+w <= p) {
          distt[v] = d+w;
          q.push(ii(d+w, v));
        }
      }
    }
    
    //*** visit all edges
    int best = -1;
    for (int i = 0; i < n; ++i) 
      for (int j = 0; j < g[i].size(); ++j) 
        if (dists[i] + g[i][j].second + distt[g[i][j].first] <= p) 
          best = max(best, g[i][j].second);
        
    cout << best << endl;
  }
}