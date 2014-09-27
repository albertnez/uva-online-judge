#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;
typedef pair<int,int> II;

const int maxn = 8;
const int maxp = 9;
const int inf = 1e9;
string map[8];
int ik = 0, jk = 0;
int dists[maxp][maxp]; // 8 P + start
int N;
int posi[maxp];
int posj[maxp];

int di[8] = {1, -1, 1, -1, 2, -2, 2, -2};
int dj[8] = {2, 2, -2, -2, 1, 1, -1, -1};

int memo[maxp][1<<maxp];

int calcd(int si, int sj, int ei, int ej) {
  if (si == ei and sj == ej) return 0;
  
  MI dist(8, VI(8, inf));
  dist[si][sj] = 0;
  queue<II> q;
  q.push(II(si, sj));
  
  while (!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    q.pop();
    if (i==ei and j==ej) return dist[i][j];
    
    for (int k = 0; k < 8; ++k) {
      int ti = i+di[k], tj = j+dj[k];
      if (ti >= 0 and ti < 8 and tj >= 0 and tj < 8 and map[ti][tj] != 'K' and map[ti][tj] != 'p') {
        dist[ti][tj] = dist[i][j]+1;
        q.push(II(ti,tj));
      }
    }
  }
  return inf;
}



void calcdists() {
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
      if (i != j)
        dists[i][j] = calcd(posi[i], posj[i], posi[j], posj[j]);
}

int f(int n, int mask) {
  if (mask == (1<<N)-1) return 0;
  if (memo[n][mask] != -1) return memo[n][mask];
  
  int &ans = memo[n][mask] = inf;
  for (int i = 0; i < N; ++i) {
    if (!(mask & (1<<i))) {
      ans = min(ans, f(i, mask|(1<<i)) + dists[n][i]);
    }
  }
  return ans;
}


int main() {
  int T; cin >> T;
  while (T--) {
    N = 1;
    memset(memo, -1, sizeof memo);
    int n;
    cin >> n;
    
    
    for (int i = 0; i < 8; ++i)
      cin >> map[i];
    
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        if (map[i][j] == 'k') {
          posi[0] = i; posj[0] = j;
        }
        else if (map[i][j] == 'P') {
          posi[N] = i;
          posj[N] = j;
          ++N;
        }
      }
    }
    
    calcdists();
    
    int ans = f(0, 1);
    
    if (ans <= n) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}