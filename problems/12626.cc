#include <iostream>
using namespace std;

int main() {
  int T; cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int m,a,r,g,i,t;
    m = a = r = g = i = t = 0;
    for (int k = 0; k < int(s.size()); ++k) {
      if (s[k] == 'M') ++m;
      else if (s[k] == 'A') ++a;
      else if (s[k] == 'R') ++r;
      else if (s[k] == 'G') ++g;
      else if (s[k] == 'I') ++i;
      else if (s[k] == 'T') ++t;
    }
    
    int ans = m;
    ans = min(ans, a/3);
    ans = min(ans, r/2);
    ans = min(ans, g);
    ans = min(ans, i);
    ans = min(ans, t);
    cout << ans << endl;
  }
}