#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
  int T; cin >> T;
  while (T--) {
    int a,b,c;
    cin >> a >> b >> c;
    
    int solx, soly, solz;
    bool found = false;
    vector<int> sol(3);
    for (int x = -21; x <= 21 and !found; ++x) if (x*x <= c and abs(x) <= b) {
      for (int y = -100; y <= 100 and !found; ++y) if (x != y and abs(x*y) <= b and x*x + y*y <= c) {
        for (int z = -100; z <= 100 and !found; ++z) if (x != z and y != z) {
          if (x+y+z == a and x*y*z == b and x*x+y*y+z*z == c) {
            sol[0] = x, sol[1] = y, sol[2] = z;
            found = true;
          }
        }
      } 
    }
    if (found) {
      sort(sol.begin(), sol.end());
      cout << sol[0] << ' ' << sol[1] << ' ' << sol[2] << endl;
    }
    else cout << "No solution." << endl;
  }
}