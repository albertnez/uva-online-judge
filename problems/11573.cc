#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;
typedef pair<int,int> II;
typedef pair<int, II> TI;
typedef vector<TI> VTI;

const int di[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dj[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const int inf = 1e9;

int main() {
  int n, m;
  cin >> n >> m;
  MI map(n, VI(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c; cin >> c;
      map[i][j] = c-'0';
    }
  }
  
  int T; cin >> T;
  while (T--) {
    int rs, cs, rd, cd;
    cin >> rs >> cs >> rd >> cd;
    --rs; --cs; --rd; --cd;
    MI dist(n, VI(m, inf));
    dist[rs][cs] = 0;
    priority_queue<TI, VTI, greater<TI> > pq;
    pq.push(TI(0, II(rs, cs)));
    int ans = 0;
    while (!pq.empty()) {
      int d = pq.top().first;
      II u = pq.top().second;
      pq.pop();
            
      if (d > dist[u.first][u.second]) continue;
      
      if (u.first == rd and u.second == cd) {
        ans = d;
        break;
      }
      
      for (int k = 0; k < 8; ++k) {
        int ni = u.first + di[k], nj = u.second + dj[k];
        if (ni >= 0 and ni < n and nj >= 0 and nj < m) {
          int cost = (map[u.first][u.second] != k);
          if (d+cost < dist[ni][nj]) {
            dist[ni][nj] = d+cost;
            pq.push(TI(d+cost, II(ni,nj)));
          }
        }
      }
    }
    cout << ans << endl;
  }
  
}