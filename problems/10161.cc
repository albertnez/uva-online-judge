#include <iostream>
using namespace std;

int main() {
  int n;
  while (cin >> n and n) {
    int s = 1;
    int h = 1;
    int d = 4;
    int w = 1;
    while (s+d <= n) {
      ++h;
      if (s > 1) ++h;
      s += d;
      d += 8;
      w += 2;
    }
    
    int x, y;
    if (s+h >= n) {
      x = w;
      y = n-s+1;
    }
    else {
      s += h;
      if (s+h >= n) {
        x = w - (n-s);
        y = h+1;
      }
      else {
        ++h;
        s += h;
        if (s+h >= n) {
          x = n-s+1;
          y = h+1;
        }
        else {
          s += h;
          x = w+1;
          y = h+1 - (n-s);
        }
      }
    }
    if (n == 3 or n == 4) x = 2;
    if (n == 4) y = 1;
    cout << x << " " << y << endl;
  }
}