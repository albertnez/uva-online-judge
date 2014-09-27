#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 76;
const int maxk = 6;
const int maxm = 4;

int memo[maxn][maxn][maxk][maxm];
int map[maxn][maxn];

const int INF = 1e9;
const int INF2 = 2e9;

int N;

int f(int i, int j, int k, int m) {
  if (i >= N or j < 0 or j >= N) return -INF;
  if (map[i][j] < 0) --k;
  if (k < 0) return -INF;
  if (i == N-1 and j == N-1) {
    return map[i][j];
  }
  if (memo[i][j][k][m] != -INF2) return memo[i][j][k][m];
  
  int ans = -INF;
  int mv = map[i][j];
  
  int val = f(i+1, j, k, 0);
  
  if (val != -INF2 and val != -INF) ans = max(ans, mv+val);
  
  
  //can move l eft
  if (!(m&(1<<1))) {
    val = f(i, j-1, k, m|(1<<0));
    if (val != -INF2 and val != -INF) ans = max(ans, mv + val);
  }
  
  //can move right
  if (!(m&(1<<0))) {
    val = f(i, j+1, k, m|(1<<1));
    if (val != -INF and val != -INF2)  ans = max(ans, mv + val);
  }
  
  return memo[i][j][k][m] = ans;
}

int main() {
  int n, k;
  int ncase = 0;
  while (cin >> n >> k and (n|k)) {
    N = n;
    for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j)
      for (int y = 0; y < maxk; ++y) for (int z = 0; z < maxm; ++z)
        memo[i][j][y][z] = -INF2;
    
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        cin >> map[i][j];
    
    
    
    int sol = f(0,0,k,0);
    if (sol != -INF) cout << "Case " << ++ncase << ": " << sol << endl;
    else cout << "Case " << ++ncase << ": impossible" << endl;
  }
}