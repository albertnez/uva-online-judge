#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> VI;

string P, T;
VI B;

int count;

void precalc() {
  int i = 0, j = -1, m = P.size();
  B[0] = -1;
  while (i < m) {
    while (j >= 0 and P[i] != P[j]) j = B[j];
    ++i; ++j;
    B[i] = j;
  }
}

void match() {
  int i = 0, j = 0, n = T.size(), m = P.size();
  
  while (i < n) {
    while (j >= 0 and P[j] != T[i]) j = B[j];
    ++i; ++j;
    if (j == m) {
      ++count;
      j = B[j];
    }
  }
}

int main() {
  int cases; cin >> cases;
  while (cases--) {
    count = 0;
    cin >> P;
    T = P+P;
    B = VI(P.size()+1, 0);
    precalc();
    match();
    cout << P.size()/(count-1) << endl;
    if (cases) cout << endl;
  }
}