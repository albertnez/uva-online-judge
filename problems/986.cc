#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<Mi> Ti;

int main() {
  int n, r, h;
  while (cin >> n >> r >> h) {
    n = n*2+1;
    Ti m(n, Mi(n, Vi(r+1, 0)));
    Ti up(n, Mi(n, Vi(r+1, 0)));
  
    m[0][0][0] = 1;
  
    for (int j = 0; j < n-1; ++j) {
      for (int i = 0; i < n; ++i) {
        for (int k = 0; k <= r; ++k) {
          //up
          if (i == h-1) {
            up[j+1][i+1][k] += m[j][i][k];
          }
          else if (i+1 < n) {
            m[j+1][i+1][k] += (m[j][i][k] + up[j][i][k]);
          }
          //down
          if (i > 0) {
            m[j+1][i-1][k] += m[j][i][k];
            //a peak
            if (k < r) 
              m[j+1][i-1][k+1] += up[j][i][k];
          }
        }
      }
    }
    cout << m[n-1][0][r] << endl;
  }
}
