#include <iostream>
using namespace std;

int main() {
  int n, k;
  while (cin >> n >> k) {
    int sol = 0;
    int butts = 0;
    while (n) {
      sol += n;
      int t = (n+butts);
      n = t/k;
      butts = t%k;
    }
    cout << sol << endl;
  }
}