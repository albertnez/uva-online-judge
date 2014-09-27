#include <iostream>
#include <cmath>
using namespace std;
const double EPS = 1e-9;
const double step = 0.001;

int p, q, r, s, t, u;
double x;

double calc() {
  return p/exp(x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u; 
}

int main() {
  cout.precision(4);
  
  while (cin >> p >> q >> r >> s >> t >> u) {  
    double lo = 0.0, hi=1.0;
    x = lo;
    double rlo = calc();
    if (abs(rlo) < EPS) {
      cout << fixed << x << endl;
      continue;
    }
    x = hi;
    double rhi = calc();
    if (abs(rlo) < EPS) {
      cout << fixed << x << endl;
    }
    
    if (rlo*rhi > EPS) cout << "No solution" << endl;
    else {
      while (abs(hi-lo) > EPS) {
        x = (hi+lo)/2;
        double ans = calc();
        if (ans > EPS) lo = x;
        else hi = x;
      }
      cout << fixed << x << endl;
    }
  }
}