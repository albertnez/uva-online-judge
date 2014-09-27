#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef vector<int> Vi;
typedef vector<char> Vc;
typedef vector<Vc> Mc;

const int maxn = 11;
const int maxd = 2000;
const int maxl = 26;
Mc map;

//(i, j, l, d)
int paths[maxn][maxn][maxl][maxd];

const int INF = 1e9;
const int mod = 20437;

const int di[4] = {0, -1, 0, 1};
const int dj[4] = {1, 0, -1, 0};

int main() {
  int n;
  int ncase = 0;
  while (cin >> n and n) {
    memset(paths, 0, sizeof paths);
    
    map = Mc(n, Vc(n));
    
    char al = 'A';
    int nl = 0;
    int si = 0, sj = 0, ei = 0, ej = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
      cin >> map[i][j];
      if (map[i][j] == 'A') {
        si = i;
        sj = j;
      }
      if (map[i][j] <= 'Z' and map[i][j] >= al) {
        al = map[i][j];
        nl = map[i][j] - 'A';
        ei = i;
        ej = j;
      }
    }
    
    paths[si][sj][0][0] = 1;
    
    for (int l = 0; l < nl; ++l) {
      for (int d = 0; d < maxd-1; ++d) {
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) { 
            for (int k = 0; k < 4; ++k) {
              int ti = i+di[k], tj = j+dj[k];
              if (ti >= 0 and ti < n and tj >= 0 and tj < n and map[ti][tj] != '#') {
                
                if (map[ti][tj] == 'A'+l+1) paths[ti][tj][l+1][d+1] = (paths[ti][tj][l+1][d+1]+paths[i][j][l][d])%mod;
                if (map[ti][tj] == '.' or map[ti][tj] <= 'A'+l) paths[ti][tj][l][d+1] = (paths[ti][tj][l][d+1]+paths[i][j][l][d])%mod;
              
                
              }
    } } } } }
    
    int sold = 0, solp = 0;
    for (int i =  maxd-1; i >= 0; --i) {
      if (paths[ei][ej][nl][i] != 0) {
        sold = i;
        solp = paths[ei][ej][nl][i]%mod;
//         cout << "sold: " << sold << ' ' << solp << endl;
      }
    }
    
//     cout << "ei: " << ei << " ej: " << ej << " nl: " << nl << " ";
    if (solp) cout << "Case " << ++ncase << ": " << sold << ' ' << solp << endl;
    else cout << "Case " << ++ncase << ": Impossible" << endl;
  }
}