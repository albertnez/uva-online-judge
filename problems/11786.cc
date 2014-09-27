#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vi;

const int maxn = 20010;

int main() {
  int T; cin >> T;
  cin.ignore();
  while (T--) {
    Vi v(maxn, -1);
    string s;
    getline(cin, s);
    int h = maxn/2;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
      int c = s[i];
      if (c == '/') {
        if (v[h] != -1) ans += i-v[h];
        ++h;
      } 
      else if (c == '\\') {
        --h;
        v[h] = i;
      }
    }
    cout << ans << endl;
  }
}