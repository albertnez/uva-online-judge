#include <iostream>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    int t = 1;
    int d = 1;
    while (t < n) {
      ++d;
      t += d;
    }
    int x = t-n;
    int a = d-x, b = x+1;
    if (d&1) swap(a,b);
    cout << "TERM " << n << " IS " << a << "/" << b << endl;
  }
}