#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;

const int BU = 1;
const int BV = 2;
const int WU = 0;
const int WV = 3;

MI map;
int n, m;


const int di[4] = {0, 0, -1, 1};
const int dj[4] = {1, -1, 0, 0};

const string types = "WAKJSD";

int dfs(int i, int j, int f, int c) {
  map[i][j] = c;
  int x = 0;
  for (int k = 0; k < 4; ++k) {
    int ni = i+di[k], nj = j+dj[k];
    if (ni >= 0 and ni < n and nj >= 0 and nj < m) {
      if (f == BU and map[ni][nj] == WU) {
	++x;
	x += dfs(ni, nj, WU, WV);
      }
      else if (map[ni][nj] == f) x += dfs(ni,nj,f,c);
    }
  }
  return x;
}

int ctoh(char c) {
  if (c >= '0' and c <= '9') return c-'0';
  return 10+(c-'a');
}


void print(const MI & map) {
  for (int i = 0; i < int(map.size()); ++i) {
    for (int j = 0; j < int(map[i].size()); ++j) {
      cout << map[i][j];
    }
    cout << endl;
  }
}

int main() {
  int ncase = 0;
  while (cin >> n >> m and (n|m)) {
    m *= 4;
    map = MI(n, VI(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; j+=4) {
	char c; cin >> c;
	int x = ctoh(c);
	for (int k = j+3; k >= j; --k) {
	  map[i][k] = (x&1);
	  x >>= 1;
	}
      }
    }
    
//   print(map);
    for (int i = 0; i < n; ++i) {
      if (map[i][0] == WU) dfs(i,0,WU,WV);
      if (map[i][m-1] == WU) dfs(i,m-1,WU,WV);
    }
    for (int j = 0; j < m; ++j) {
      if (map[0][j] == WU) dfs(0,j,WU,WV);
      if (map[n-1][j] == WU) dfs(n-1,j,WU,WV);
    }
    
    string ans = "";
    
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
	if (map[i][j] == BU)
	  ans += types[dfs(i,j,BU,BV)];
      }
    }
    
    sort(ans.begin(), ans.end());
    cout << "Case " << ++ncase << ": " << ans << endl;
  }
  
}