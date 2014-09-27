#include <iostream>
using namespace std;

int main() {
  int a, b, ncase = 0;
  while (cin >> a >> b and (a|b)) {
    int sol = 0;
    if (a > b) {
      int d = a-b;
      sol = d/b + (d%b != 0);
    }
    if (sol <= 26) cout << "Case " << ++ncase << ": " << sol << endl;
    else cout << "Case " << ++ncase << ": impossible" << endl;
  }
}