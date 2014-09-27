#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;

const int maxn = 8;


MI G(maxn);
VI map;
int act;
VI dist;
VI pos;
int n;


int maxdist() {
  VI tmp(n);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (pos[j] == i) tmp[i] = j;
  
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < int(G[i].size()); ++j) {
      ans = max(ans, abs(tmp[i]-tmp[G[i][j]]));
    }
  }
  return ans;
}

int main () {
  string s;
  while (cin >> s and s != "#") {
    G = MI(maxn);
    
    vector<char> tmp;
    vector<bool> used(26, false);
    for (int i = 0; i < int(s.size()); ++i) {
      if (s[i] >= 'A' and s[i] <= 'Z' and !used[s[i]-'A']) {
        used[s[i]-'A'] = true;
        tmp.push_back(s[i]);
      }
    }
    sort(tmp.begin(), tmp.end());
    
    n = tmp.size();
    map = VI(26, -1);
    vector<char> names(n);
    
    for (int i = 0; i < int(tmp.size()); ++i) {
      names[i] = tmp[i];
      map[tmp[i]-'A'] = i;
    }
    
    
    
    for (int i = 0; i < int(s.size()); ++i) {
      int src = map[s[i]-'A'];
      i += 2;
      while (i < int(s.size()) and s[i] != ';') {
        int dst = map[s[i]-'A'];
        G[src].push_back(dst);
        ++i;
      }
    }
    
    
    pos.assign(n, 0);
    for (int i = 0; i < n; ++i)
      pos[i] = i;
    
    int ans = 1e9;
    VI best(pos);
    
    do {
      int d = maxdist();
      if (d < ans) {
        ans = d;
        best = pos;
      }
    } while (next_permutation(pos.begin(), pos.end()));
    
    for (int i = 0; i < n; ++i)
      cout << names[best[i]] << ' ';
    cout << "-> " << ans << endl;
  }
}