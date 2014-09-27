#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef vector<string> Vs;
typedef vector<Vs> Ms;

typedef pair<int,int> ii;
typedef pair<ii, int> ti;
typedef pair<int, ti> qi;

typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<Mi> Ti;

const int INF = 1e9;

const int di[6] = {0, 0, -1, 1, 0, 0};
const int dj[6] = {-1, 1, 0, 0, 0, 0};
const int dk[6] = {0, 0, 0, 0, -1, 1};

int main() {
  int l, r, c;
  while (cin >> l >> r >> c and (l|r|c)) {
    Ms m(l, Vs(r));
    ti start, end;
    for (int k = 0; k < l; ++k)
      for (int i = 0; i < r; ++i) {
        cin >> m[k][i];
        for (int j = 0; j < c; ++j)
          if (m[k][i][j] == 'S') start = ti(ii(k, i), j);
          else if (m[k][i][j] == 'E') end = ti(ii(k, i), j);
      }
    
    
    Ti dist(l, Mi(r, Vi(c, INF)));
    dist[start.first.first][start.first.second][start.second] = 0;
    priority_queue<qi, vector<qi>, greater<qi> > q;
    q.push(qi(0, start));
    
    int sol = INF;
    while (!q.empty()) {
      int d = q.top().first;
      ti u = q.top().second;
      q.pop();
      if (u == end) {
        sol = d;
        break;
      }
      int uk = u.first.first, ui = u.first.second, uj = u.second;
      if (d > dist[uk][ui][uj]) continue;
      for (int i = 0; i < 6; ++i) {
        int nk = uk + dk[i], ni = ui + di[i], nj = uj + dj[i];
        if (nk >= 0 and nk < l and ni >= 0 and ni < r and nj >= 0 and nj < c 
                    and m[nk][ni][nj] != '#' and d+1 < dist[nk][ni][nj]) {
          dist[nk][ni][nj] = d+1;
          q.push(qi(d+1, ti(ii(nk, ni), nj)));          
        }
      }
    }
    
    if (sol == INF) cout << "Trapped!" << endl;
    else cout << "Escaped in " << sol << " minute(s)." << endl;
  }
}