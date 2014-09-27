#include <iostream>
#include <map>
using namespace std;
int main() {
  int T; cin >> T;
  while (T--) {
    map<int,int> mii;
    int n; cin >> n;
    int ind = 0, sol = 0;
    for (int i = 0; i < n; ++i) {
      int k; cin >> k;
      if (mii.find(k) == mii.end())
        mii[k] = i;
      else {
        if (mii[k] >= ind) {
          sol = max(sol, i-ind);
          ind = mii[k]+1;
        }
        mii[k] = i;
      }
    }
    sol = max(sol, n-ind);
    cout << sol << endl;
  }
}