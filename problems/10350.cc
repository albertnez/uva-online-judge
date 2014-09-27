#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;

const int INF = 1e9;
int main() {
  string s;
  while (cin >> s) {
    int n, m;
    cin >> n >> m;
    Mi g(n, Vi(m, INF));
    for (int j = 0; j < m; ++j) g[0][j] = 0;
    
    for (int i = 0; i < n-1; ++i) {
      for (int j = 0; j < m; ++j) {
        for (int k = 0; k < m; ++k) {
          int t; cin >> t;
          g[i+1][k] = min(g[i+1][k], g[i][j] + 2 + t);
        }
      }
    }
    
    int ans = INF;
    for (int j = 0; j < m; ++j) ans = min(ans, g[n-1][j]);
    cout << s << endl << ans << endl;
  }
}