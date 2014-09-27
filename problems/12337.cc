#include <iostream>
#include <vector>
using namespace std;

bool solve(const string s, int r, int c) {
  vector<vector<int> > m(r, vector<int>(c, 0));
  
  m[0][0] = s[0];
  int i = 0, j = 0;
  int act = 1;
  bool pos = true;
  while (pos) {
    pos = false;
    while (j+1 < c and !m[i][j+1]) {
      pos = true;
      ++j;
      m[i][j] = s[act++];
    }
    while (i+1 < r and !m[i+1][j]) {
      pos = true;
      ++i;
      m[i][j] = s[act++];
    }
    while (j-1 >= 0 and !m[i][j-1]) {
      pos = true;
      --j;
      m[i][j] = s[act++];
    }
    while (i-1 >= 0 and !m[i-1][j]) {
      pos = true;
      --i;
      m[i][j] = s[act++];
    }
  }
  
  for (int j = 0; j < c; ++j) 
    for (int i = 1; i < r; ++i) 
      if (m[i][j] != m[i-1][j]) return false;
  
  return true;
}


int main() {
  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    string s; cin >> s;
    
    int ans = 1e9;
    for (int i = 2; i*i <= int(s.size()); ++i) {
      if (int(s.size())%i == 0) {
        int d = int(s.size())/i;
        if (solve(s, i, d) or solve(s, d, i))
          ans = min(ans, i+d);
      }
    }
    
    if (ans == 1e9) ans = -1;
    cout << "Case " << ++ncase << ": " << ans << endl;
  }
}