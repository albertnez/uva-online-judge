#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 102;

int best[maxn];
int N, K, T;


int main() {
  ios_base::sync_with_stdio(false);
  int cases;
  cin >> cases;
  while (cases--) {
    memset(best, 0 , sizeof best);
    cin >> N >> K >> T;
    vector<vector<int> > v(N+1, vector<int>(3, 0));

    for (int j = 0; j < 3; ++j)
      for (int i = 1; i <= N; ++i)
        cin >> v[i][j];
    
    sort(v.begin(), v.end());
        
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
      for (int j = 0; j < i; ++j) {
        if (v[i][0]-v[j][0] >= abs(v[i][2]-v[j][2]) and 
          (best[j] or j == 0)) {
          best[i] = max(best[i], best[j] + v[i][1]);
          ans = max(ans, best[i]);
        }
      }
    }
    cout << ans << endl;
    if (cases) cout << endl;
  }
}