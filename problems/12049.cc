#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef map<int,int> mii;

int main() {
  int T; cin >> T;
  int n, m;
  while (T--) {
    cin >> n >> m;
    mii a;
    for (int i = 0; i < n; ++i) {
      int k; cin >> k;
      a[k]++;
    } 
    for (int i = 0; i < m; ++i) {
      int k; cin >> k;
      a[k]--;
    }
    int sum = 0;
    for (mii::iterator it = a.begin(); it != a.end(); ++it)
      sum += abs(it->second);
    cout << sum << endl;
  }
}