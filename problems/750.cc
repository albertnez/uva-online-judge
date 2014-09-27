#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;

Mi sols;
Vi tv(8);
int col, row, d1, d2, jmp, soln;

int bt(int n) {
  if (n == jmp) bt(n+1);
  else if (n == 8) {
    if (soln+1 <= 9) cout << ' ';
    cout << ++soln << "     ";
    for (int i = 0; i < 8; ++i)
      cout << ' ' << tv[i]+1;
    cout << endl;
  }
  else {
    for (int i = 0; i < 8; ++i) {
      if (!(row&(1<<i)) and !(col&(1<<n)) and !(d1&(1<<(8-i+n))) and !(d2&(1<<(i+n)))) {
        row |= 1<<i;
        col |= 1<<n;
        d1  |= 1<<(8-i+n);
        d2  |= 1<<(i+n);
        tv[n] = i;
        bt(n+1);
        row &= ~(1<<i);
        col &= ~(1<<n);
        d1  &= ~(1<<(8-i+n));
        d2  &= ~(1<<(i+n));
      } 
    }
  }
}

int main() {
  int T; cin >> T;
  while (T--) {
    int i, j; cin >> i >> j; --i; --j;
    row = 1<<i;
    col = 1<<j;
    d1 = 1<<(8-i+j);
    d2 = 1<<(i+j);
    jmp = j;
    tv[j] = i;
    soln = 0;
    
    cout << "SOLN       COLUMN" << endl
         << " #      1 2 3 4 5 6 7 8" << endl << endl;

    bt(0);
    
    if (T) cout << endl;
  }
}