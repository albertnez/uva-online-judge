#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int T; cin >> T;
  string line;
  getline(cin,line);
  while (T--) {
    int n = 0;
    getline(cin,line);
    vector<bool> used(27, false);
    vector<int> v;
    for (int i = 0; i < int(line.size()); ++i) {
      if (line[i] >= 'A' and line[i] <= 'Z') {
        int x = line[i] - 'A' + 1;
        if (!used[x]) {
          v.push_back(x);
          used[x] = true;
          ++n;
        }
      }
    }
    sort(v.begin(), v.end());
    
    int maxl = 0;
    int maxw = 1;
    vector<int> dp(n, 1), ways(n, 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (5*v[j] <= 4*v[i]) {
          if (dp[j]+1 == dp[i]) ways[i] += ways[j];
          else if (dp[j]+1 > dp[i]) {
            ways[i] = ways[j];
            dp[i] = dp[j]+1;
          }
        }
      }
      
      if (maxl == dp[i]) maxw += ways[i];
      else if (dp[i] > maxl) {
        maxl = dp[i];
        maxw = ways[i];
      }
    }
    
    cout << maxl << ' ' << maxw << endl;
  }
}