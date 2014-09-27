#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
  cout.precision(4);
  int T; cin >> T;
  while (T--) {
    int n, f; cin >> n >> f;
    ++f;
    vector<int> v(n), used(n, 0);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      v[i]*=v[i];
    }
    
    
    while (f--) {
      double maxim = 0;
      int ind = 0;
      for (int i = 0; i< n; ++i) {
        if (used[i] == 0) {
          if (v[i] > maxim) {
            maxim = v[i];
            ind = i;
          }
        }
        else {
          double x = v[i]/(1.0+used[i]);
          if (x > maxim) {
            maxim = x;
            ind = i;
          }
        }
      }
      ++used[ind];
    }
    double ans = 1e9;
    for (int i = 0; i < n; ++i)
      if (used[i])
        ans = min(ans, double(v[i])/used[i]);

    cout << fixed << ans*M_PI << endl;
  }
}