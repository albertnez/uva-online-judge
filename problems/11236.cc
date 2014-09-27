#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const double MAX = 20.0;
const double EPS = 1e-9;

double norm(double d) { return double(int(d*100+0.001))/100.0; }

int main() {
  cout.precision(2);
  set<vector<double> > ms;
  for (double i = 0.01; i+i+i+i <= MAX+EPS and i*i*i*i <= MAX+EPS; i += 0.01)
    for (double j = i; i+j+j+j <= MAX+EPS and i*j*j*j <= MAX+EPS; j += 0.01)
      for (double k = j; i+j+k+k <= MAX+EPS and i*j*k*k <= MAX+EPS; k += 0.01) {
        double l = (i+j+k)/(i*j*k-1);

        if (fabs(l-norm(l)) < EPS) {
          if (l > 0 and (i+j+k+l <= MAX+EPS) and fabs(i+j+k+l - i*j*k*l) < EPS) {
            vector<double> v(4); v[0] = norm(i); v[1] = norm(j); v[2] = norm(k); v[3] = norm(l);
            sort(v.begin(), v.end());
            if (ms.count(v)==0) {
              ms.insert(v);
              cout << fixed << v[0] << ' ' << v[1] << ' ' << v[2] << ' ' << v[3] << endl;
            }
          }
        }
      }
}