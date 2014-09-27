#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef pair<int,int> ii;

vector<bool> vis;
Mi g;
int N;
int remaining;
int maxdist = 0;
Vi worst;

const int INF = 1e9;

queue<int> leaves;
Vi deg;

ii findCenter() {
  ii sol(-1, -1);
  queue<int> aux;

  while (remaining > 2) {
    int deleted = 0;
    while (!leaves.empty()) {
      ++deleted;
      int u = leaves.front(); leaves.pop();
      deg[u] = 0;
      bool find = true;
      for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        --deg[v];
        if (deg[v] == 1) aux.push(v);
      }
    }
    remaining -= deleted;
    swap(leaves, aux);
  }
  
  if (!leaves.empty()) {
    sol.first = leaves.front();
    leaves.pop();
  }
  if (!leaves.empty()) sol.second = leaves.front();
  
  if (sol.first > sol.second)
    swap(sol.first, sol.second);
  
  return sol;
}

void bfs(int u) {
  Vi dist(N, INF);
  queue<int> q;
  q.push(u);
  dist[u] = 0;
  
  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int i = 0; i < g[u].size(); ++i) {
      int v = g[u][i];
      if (dist[u]+1 < dist[v]) {
        dist[v] = dist[u]+1;
        if (dist[v] == maxdist) worst.push_back(v);
        else if (dist[v] > maxdist) {
          maxdist = dist[v];
          worst.assign(1, v);
        }
        q.push(v);
      }
    }
  }
}

int main() {
  int n;
  while (cin >> n) {
    N = n;
    remaining = n;
    g = Mi(n);
    deg.assign(n, 0);
    worst.assign(0,0);
    maxdist = 0;
    leaves = queue<int>();
    
    for (int i = 0; i < n; ++i) {
      int k; cin >> k;
      g[i] = Vi(k);
      deg[i] = k;
      if (k == 1) leaves.push(i);
      
      for (int j = 0; j < k; ++j) {
        int q; cin >> q;
        g[i][j] = q-1;
      }
    }
    
    ii center = findCenter();
    if (center.first > -1) bfs(center.first );
    if (center.second > -1) bfs(center.second);
    
    sort(worst.begin(), worst.end());
    
    cout << "Best Roots  : ";
    if (center.first > -1) cout << center.first+1 << ' ';
    cout << center.second+1 << endl;
    
    cout << "Worst Roots :";
    for (int i = 0; i < worst.size(); ++i) cout << ' ' << worst[i]+1;
    cout << endl;
    
  }
}