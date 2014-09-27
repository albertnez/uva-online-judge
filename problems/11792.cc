#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<bool> Vb;
typedef pair<int,int> ii;
const int INF = 1e9;
int main() {
  int T; cin >> T;
  while (T--) {
    int n, l;
    cin >> n >> l;
    Mi g(n);
    Vb used(n, false), vimp(n, false);
    set<int> important;
    set<ii> edges;
    while (l--) {
      int prev, next;
      cin >> prev >> next;
      --prev;
      
      if (used[prev]) {
        important.insert(prev);
        vimp[prev] = true;
      }
      used[prev] = true;
      
      while (next) {
        --next;

        if (!used[next]) {
          used[next] = true;
        }
        else {
          important.insert(next);
          vimp[next] = true;
        }

        g[prev].push_back(next);
        g[next].push_back(prev);
        
        prev = next;
        cin >> next;
      }
    }
    
    int sol = 0;
    int best = INF;
    for (set<int>::iterator it = important.begin(); it != important.end(); ++it) {
//       cout << "important: " << *it;
      queue<int> q;
      Vi dist(n, INF);
      dist[*it] = 0;
      q.push(*it);
      int sum = 0;
      while (!q.empty()) {
        int u = q.front(); q.pop();
        if (vimp[u] and u != *it) sum += dist[u];
        for (int i = 0; i < g[u].size(); ++i) {
          int v = g[u][i];
          if (dist[v] == INF) {
            dist[v] = dist[u] +1;
            q.push(v);
          }
        }
      }
      if (sum < best) {
        best = sum;
        sol = *it;
      }
    }
    cout << "Krochanska is in: " << sol+1 << endl;
  }
}