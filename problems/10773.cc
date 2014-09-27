#include <iostream>
#include <cmath>
using namespace std;

int main() {
  cout.precision(3);
  int T, ncase = 0; cin >> T;
  while (T--) {
    double d, v, u;
    cin >> d >> v >> u;
    if (v >= u or v == 0) { 
      cout << "Case " << ++ncase << ": can't determine" << endl;
    } else {
      double a = acos(v/u);
      a = u*sin(a);
      a = d/a;
      double b = d/u;
      cout << "Case " << ++ncase << ": " << fixed << fabs(a-b) << endl;
    }
  }
}