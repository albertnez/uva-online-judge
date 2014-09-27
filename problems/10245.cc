#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<double,double> pt;
inline bool sortX(const pt & a, const pt & b) { return a.first < b.first; } 
inline bool sortY(const pt & a, const pt & b) { return a.second < b.second; }

const double infinity = 1e9;

double dist(const pt & a, const pt & b) {
  return hypot(a.first-b.first, a.second-b.second);
}

const int maxn = 10005;
vector<pt> vx, vy;

double fun(int l, int r) {
  if (r-l == 1) return infinity;
  if (r-l == 2) return dist(vx[l], vx[l+1]);
  
  int m = (l+r)/2;
  double d = min(fun(l,m),fun(m,r));
  vy.clear();
  for (int i = l; i < r; ++i) {
    if (abs(vx[i].first - vx[m].first) < d)
      vy.push_back(vx[i]);
  }
  sort(vy.begin(), vy.end(), sortY);
  for (int i = 0; i < int(vy.size()); ++i) {
    for (int j = i+1; j < int(vy.size()) and abs(vy[i].second-vy[j].second) < d; ++j) {
      d = min(d, dist(vy[i], vy[j]));
    }
  }
  return d;
}

int main() {
  cout.precision(4);
  cout.setf(ios::fixed);
  int n;
  while (cin >> n and n) {
    vx = vector<pt>(n);
    for (int i = 0; i < n; ++i) {
      cin >> vx[i].first >> vx[i].second;
    }
    sort(vx.begin(), vx.end());
    double d = fun(0,n);
    if (d < 10000) cout << d << endl;
    else cout << "INFINITY" << endl;
  }
}