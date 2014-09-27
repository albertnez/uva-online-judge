#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Vi;

const int MAX = 1<<9;
Vi steps(MAX, -1);
bool bit(int n, int i) {
  return (n&(1<<i));
}

int f(int n) {
  int x = 0;
  x |= ((bit(n, 1) + bit(n, 3))%2) << 0;
  x |= ((bit(n, 0) + bit(n, 2) + bit(n, 4))%2) << 1;
  x |= ((bit(n, 1) + bit(n, 5))%2) << 2;
  x |= ((bit(n, 0) + bit(n, 4) + bit(n, 6))%2) << 3;
  x |= ((bit(n, 1) + bit(n, 3) + bit(n, 5) + bit(n, 7))%2) << 4;
  x |= ((bit(n, 2) + bit(n, 4) + bit(n, 8))%2) << 5;
  x |= ((bit(n, 3) + bit(n, 7))%2) << 6;
  x |= ((bit(n, 4) + bit(n, 6) + bit(n, 8))%2) << 7;
  x |= ((bit(n, 5) + bit(n, 7))%2) << 8;
  return x;
}

void precalc(int n) {
  if (steps[n] != -1) return;
  if (f(n) == n) {
    steps[n] = 0;
  }
  else {
    precalc(f(n));
    steps[n] = steps[f(n)]+1;
  }
}

void print(int n) {
  for (int i = 0; i < 9; ++i) {
    if (i%3==0) cout << endl;
    cout << bit(n, i);
  }
  cout << endl;
}

int main() {
  for (int i = 0; i < MAX; ++i)
    precalc(i);
  int T; cin >> T;
  while (T--) {
    int x = 0;
    for (int i = 0; i < 9; ++i) {
      char c; cin >> c;
      x |= (c-'0') << i;
    }
    
    cout << steps[x]-1 << endl;
  }
}