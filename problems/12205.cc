#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> VI;

int main() {
  int n, m;
  while (cin >> n >> m and (n|m)) {
    VI start(n), end(n);
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> a >> a >> b;
      start[i] = a;
      end[i] = a+b;
    }
    
    while (m--) {
      int a, b;
      cin >> a >> b;
      
      int ans = 0;
      for (int i = 0; i < n; ++i)
        if (start[i] < a+b and end[i] > a) ++ans;
      cout << ans << endl;
    }
  }
}