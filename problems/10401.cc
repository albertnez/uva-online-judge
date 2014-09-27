#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef unsigned long long ll;
typedef vector<ll> Vll;
typedef vector<Vll> Mll;
typedef vector<int> Vi;

int f(char c) {
  if (c >= '1' and c <= '9') return c-'1';
  return c-'A'+9;
}

int main() {
  string s;
  while (cin >> s) {
    int n = s.size();
    Mll g(n, Vll(n, 0));
    for (int i = 0; i < n; ++i) g[i][0] = 1;
    
    for (int j = 0; j < n-1; ++j) {
      if (s[j] != '?') {
        int r = f(s[j]);
        if (s[j+1] != '?') {
          int r2 = f(s[j+1]);
          if (abs(r-r2) > 1)
            g[r2][j+1] += g[r][j];
        }
        else {
          for (int i = 0; i < n; ++i) {
            if (abs(r-i) > 1) 
              g[i][j+1] += g[r][j];
           
          }
        }
      }
      else {
        for (int i = 0; i < n; ++i) {
          if (s[j+1] != '?') {
            int r = f(s[j+1]);
            if (abs(i-r) > 1)
              g[r][j+1] += g[i][j];
          }
          else {
            for (int k = 0; k < n; ++k)
              if (abs(i-k) > 1)
                g[k][j+1] += g[i][j];
          }
        }
      }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i)
      ans += g[i][n-1];
    cout << ans << endl;
    
  }
}