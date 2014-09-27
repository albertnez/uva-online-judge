#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, p;
  while (cin >> n >> p and (n|p)) {
    int m = (n+1)/2;
    int i = m, j = m, x = 1, d = 7;
    while (p >= x+d) {
      ++j;
      x += d;
      d += 8;
    }
    bool found = false;
    d = j-m;
    if (p <= x+d+1) i += p-x;
    else {
      i += d+1;
      x += d+1;
      if (p <= x+2*d+1) j -= p-x;
      else {
        j -= 2*d+1;
        x += 2*d+1;
        if (p <= x+2*d+2) i -= p-x;
        else {
          i -= 2*d+2;
          x += 2*d+2;
          if (p <= x+2*d+2) j += p-x;
          else {
            j += 2*d+2;
            x += 2*d+2;
            i += p-x;
          }
        }
      }
    }
      
    cout << "Line = " << i << ", column = " << j << "." << endl;    
  }
}
  