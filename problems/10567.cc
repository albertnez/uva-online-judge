#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;

const int inf = 1e9;
const int maxn = 52;

int getid(char c) {
  if (c >= 'a' and c <= 'z') return c-'a';
  return c-'A'+26;
}

int main() {
  ios_base::sync_with_stdio(false);
  string s;
  MI m(maxn);
  cin >> s;
  int act = 0;
  for (int i = 0; i < int(s.size()); ++i) {
    int id = getid(s[i]);
    m[id].push_back(act++);
  }
  int q; cin >> q;
  while (q--) {
    int st = -1;
    act = -1;
    
    string sq; cin >> sq;
    for (int i = 0; act < inf and i < int(sq.size()); ++i) {
      int id = getid(sq[i]);
      VI::iterator it = upper_bound(m[id].begin(), m[id].end(), act);
      if (it == m[id].end()) act = inf;
      else act = *it;
      if (st < 0) st = act;
    }
    
    if (act < inf) cout << "Matched " << st << ' ' << act << endl;
    else cout << "Not matched" << endl;
  }
}