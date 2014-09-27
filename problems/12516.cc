#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
int main() {
  int n, m;
  while (cin >> n >> m and (n|m)) {
    vector<vector<bool> > left(n, vector<bool>(m, false)), right(left);
    int npc; cin >> npc;
    while (npc--) {
      char a, p;
      int c;
      cin >> a >> c >> p;
      --c;
      int r = a - 'A';
      if (p == '-') {
        left[r][c] = true;
        if (c > 0) right[r][c-1] = true;
      }
      else {
        right[r][c] = true;
        if (c < m-1) left[r][c+1] = true;
      }
    }
    int z; cin >> z;
    VPII f(z);
    for (int i = 0; i < z; ++i) {
      char a;
      cin >> a >> f[i].second;
      f[i].first = a-'A';
      --f[i].second;
    }
    sort(f.begin(), f.end());
    int nz = z;
    for (int i = 0; i < z; ++i) {
      int r = f[i].first, c = f[i].second;
      if (!left[r][c]) {
        if (c > 0) right[r][c-1] = true;
        --nz;
      }
      else if (!right[r][c]) {
        if (c < m-1) left[r][c+1] = true;
        --nz;
      }
    }
    
    if (nz) cout << "NO" << endl;
    else cout << "YES" << endl;
    
  }
}