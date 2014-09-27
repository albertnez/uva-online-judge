#include <iostream>
#include <cstring>
using namespace std;
const int inf = 1e9;
string s;

const int maxn = 1001;
int pal[maxn][maxn];
int memo[maxn];

void pre() {
  memset(pal, 0, sizeof pal);
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    int j = 0;
    while (i-j >= 0 and i+j < n and s[i-j] == s[i+j]) {
      pal[i-j][i+j] = 1;
      ++j;
    }
    j = 0;
    while (i-j >= 0 and i+j+1 < n and s[i-j] == s[i+j+1]) {
      pal[i-j][i+j+1] = 1;
      ++j;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  while (T--) {
    memset(memo, -1, sizeof memo);
    cin >> s;
    pre();
    int n = s.size();
    memo[0] = 1;
    for (int i = 1; i < n; ++i) {
      int ans = i+1; 
      if (pal[0][i]) ans = 1;
      else {
        for (int j = 0; j < i; ++j) {
          if (pal[j+1][i]) ans = min(ans, memo[j]+1); 
        }
      }
      memo[i] = ans;
//       cout << "memo[" << i << "] = " << memo[i] << endl;
    }
//    cout << f(0, s.size()-1) << endl;
    cout << memo[n-1] << endl;
  }
}