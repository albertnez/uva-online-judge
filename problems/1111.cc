#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<double,double> pt;
#define X first
#define Y second

const double eps = 1e-9;

double cross(const pt & a, const pt & b) {
  return (a.X * b.Y - a.Y * b.X);
}

double dot(const pt & a, const pt & b) {
  return (a.X*b.X + a.Y*b.Y);
}

pt toVec(const pt & a, const pt & b) {
  return pt(b.X-a.X, b.Y-a.Y);
}

double sq(const pt & a) {
  return a.X*a.X + a.Y*a.Y;
}

pt translate(const pt & a, const pt & vec) {
  return pt(a.X + vec.X, a.Y + vec.Y);
}

pt scale(const pt & vec, double u) {
  return pt(vec.X * u, vec.Y * u);
}

double dist(const pt& a, const pt& b) {
  return hypot(a.X-b.X, a.Y-b.Y);
}

double distToLine(const pt & a, const pt & b, const pt & p) {
  pt ab = toVec(a,b);
  pt ap = toVec(a,p);
  double u = dot(ab, ap)/sq(ab);
  pt c = translate(a, scale(ab, u));
  return dist(c, p);
}

bool ccw(const pt & a, const pt & b, const pt & c) {
  return cross(pt(b.X-a.X, b.Y-a.Y), pt(c.X-a.X, c.Y-a.Y)) > 0;
}

pt reference;

bool collinear(const pt & a, const pt & b, const pt & c) {
  return (abs(cross(toVec(a, b), toVec(a, c))) < eps);
}

bool angleCmp(const pt & a, const pt & b) {                 // angle-sorting function
  if (collinear(reference, a, b))                               // special case
    return dist(reference, a) < dist(reference, b);    // check which one is closer
  double d1x = a.X - reference.X, d1y = a.Y - reference.Y;
  double d2x = b.X - reference.X, d2y = b.Y - reference.Y;
  return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0; }   // compare two angles

int main() {
  cout.precision(2);
  cout.setf(ios::fixed);
  int n;
  int ncase = 0;
  while (cin >> n and n) {
    vector<pt> points(n);
    for (int i = 0; i < n; ++i) {
      cin >> points[i].X >> points[i].Y;
    }
        
    sort(points.begin(), points.end());
    reference = points[0];
    
//     for (int i = 0; i < n; ++i) {
//       cout << "point " << i << ": (" << points[i].X << "," << points[i].Y << ")" << endl;
//     }
//     cout << endl;
    sort(points.begin()+1, points.end(), angleCmp);
//     for (int i = 0; i < n; ++i) {
//       double a = asin((points[i].Y-reference.Y) / hypot(points[i].X-reference.X, points[i].Y-reference.Y));
//       cout << "point " << i << ": (" << points[i].X << "," << points[i].Y << ")  a: " << a << endl;
//     }
    
    vector<pt> possible;
    possible.push_back(points[n-1]);
    possible.push_back(points[0]);
    possible.push_back(points[1]);
    
    for (int i = 2; i < n; ++i) {
      pt a = possible[possible.size()-2];
      pt b = possible[possible.size()-1];
      pt c = points[i];
      
      while (!ccw(a, b, c)) {
        possible.pop_back();
        b = a;
        a = possible[possible.size()-2];
      }
      possible.push_back(c);
    }
    
    
    
//     cout << " hull size: " << possible.size() << endl;
/*    
    for (int i = 1; i < int(possible.size()); ++i) {
      cout << "(" << possible[i].X << "," << possible[i].Y << ") ";
    }
    cout << endl;
    */
    double mn = 1000000000;
    for (int i = 1; i < int(possible.size()); ++i) {
      double mx = 0;
      for (int j = 1; j < int(possible.size()); ++j) {
//         cout << "points: (" << points[i-1].X << "," << points[i-1].Y << "), (" << points[i].X << "," << points[i].Y << "),  (" << points[j].X << "," << points[j].Y << ")" << endl;
        mx = max(mx, distToLine(possible[i-1], possible[i], possible[j]));
      }
      mn = min(mn, mx);
    } 
    mn = ceil(mn*100.0)/100.0;
    cout << "Case " << ++ncase << ": " <<  mn << endl;
  }
}