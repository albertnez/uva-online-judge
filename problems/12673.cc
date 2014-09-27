#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n, g;
  while (cin >> n >> g) {
    vector<int> v;
    int points = 0;
    for (int i = 0; i < n; ++i) {
      int a, b; cin >> a >> b;
      if (a <= b) v.push_back(b-a+1);
      else points += 3;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < int(v.size()); ++i) {
      int t = min(g, v[i]);
      g-= t;
      v[i] -= t;
      if (!v[i]) points += 3;
      else if (v[i] == 1) ++points;
    }
    cout << points << endl;
  }
}