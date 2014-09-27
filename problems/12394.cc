#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
  int k, n;
  while (cin >> k >> n and (n|k)) {
    vector<string> names(n);
    int ans = 0;
    vector<int> reviews(n, 0);
    vector<bool> ok(n, true);
    vector<vector<int> > commands(n, vector<int> (k));
    for (int i = 0; i < n; ++i) {
      cin >> names[i];
      for (int j = 0; j < k; ++j)
        cin >> commands[i][j];
    }
    
    for (int i = 0; i < n; ++i) {
      vector<bool> visited(n, false);
      for (int j = 0; j < k; ++j) {
        int m = commands[i][j]-1;
        if (visited[m]) ok[m] = false;
        else if (m == i) ok[m] = false;
        else if (names[m] == names[i]) ok[m] = false;
        else {
          visited[m] = true;
          ++reviews[m];
        }
      } 
    }
    for (int i = 0; i < n; ++i)
      if (reviews[i] != k or !ok[i]) ++ans;
    
    if (!ans) cout << "NO PROBLEMS FOUND" << endl;
    else if (ans == 1) cout << "1 PROBLEM FOUND" << endl;
    else cout << ans << " PROBLEMS FOUND" << endl;  
  }
}