#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;

Mi sols;
Vi tv(8);
int col, row, d1, d2;

int bt(int n) {
  if (n == 8)
    sols.push_back(tv);
  else {
    for (int j = 0; j < 8; ++j) {
      if (!(row&(1<<n)) and !(col&(1<<j)) and !(d1&(1<<(8-n+j))) and !(d2&(1<<(n+j)))) {
        row |= 1<<n;
        col |= 1<<j;
        d1  |= 1<<(8-n+j);
        d2  |= 1<<(n+j);
        tv[n] = j+1;
        bt(n+1);
        row &= ~(1<<n);
        col &= ~(1<<j);
        d1  &= ~(1<<(8-n+j));
        d2  &= ~(1<<(n+j));
      } 
    }
  }
}

int main() {
  bt(0);
  Vi v(8);
  int ncase = 0;
  while (cin >> v[0]) {
    for (int i = 1; i < 8; ++i)
      cin >> v[i];
    
    int best = 8;
    for (int i = 0; i < sols.size(); ++i) {
      int t = 0;
      for (int j = 0; j < 8; ++j)
        if (v[j] != sols[i][j]) ++t;
      best = min(best, t);
    }
    cout << "Case " << ++ncase << ": " << best << endl;
  }
}