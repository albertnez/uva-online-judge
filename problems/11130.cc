#include <iostream>
#include <cmath>
using namespace std;

const double eps = 1e-9;

int main() {
  int w, h, a, s;
  double v;
  while (cin >> w >> h >> v >> a >> s and w) {
    int numw = 0, numh = 0;
    
    double arad = a*(M_PI/180.0);
    double accel = double(v)/double(s);
    double dx = v*cos(arad)*s - 0.5*(accel*cos(arad))*s*s;
    double dy = v*sin(arad)*s - 0.5*(accel*sin(arad))*s*s;
    
    // vertical
//     cout << " dx " << dx << "  dy: " << dy << endl;
    
    dx -= 0.5*w;
    if (dx > -eps)
      numw = 1 + dx/double(w);
    
    dy -= 0.5*h;
    if (dy > -eps)
      numh = 1 + dy/double(h);
    
    cout << numw << ' ' << numh << endl;
  } 
}