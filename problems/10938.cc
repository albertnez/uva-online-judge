#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;

MI G;
VI path;

int dfs(int s, int prev, int u, int d) {
  path[d] = s;
  if (s == u) return d;
  int ans = -1;
  for (int i : G[s]) {
    if (i != prev) {
      ans = dfs(i, s, u, d+1);
      if (ans > -1) return ans;
    }
  }
  return ans;
}


int main() {
  int n;
  while (cin >> n and n) { 
    G = MI(n);
    path = VI(n);
    for (int i = 0; i < n-1; ++i) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a; --b;
      int ans = dfs(a, -1, b, 0);
      if (ans&1) {
        int x = path[ans/2]+1, y = path[ans/2+1]+1;
        cout << "The fleas jump forever between " << min(x,y) << " and " << max(x,y) << "." << endl;
      }
      else {
        cout << "The fleas meet at " << path[ans/2]+1 << "." << endl;
      }
    }
  }
}
