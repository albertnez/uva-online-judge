using namespace std;
#include <iostream>

int main() {
  int n;
  while (cin >> n and n >= 0) {
    int found = 0;
    --n;
    
    for (int i = 2; i*i <= n+2; ++i) {
      int cn = n;
      if (n%i == 0) {
        bool pos = true;
        for (int t = 0; t < i; ++t) {
          if (cn%i != 0) pos = false;
          cn = cn-(cn/i + 1);
        }
        ++cn;
        if (pos and (cn%i) == 0 and i > found) found = i;
      }
    }
    
    if (found) cout << n+1 << " coconuts, " << found << " people and 1 monkey" << endl;
    else cout << n+1 << " coconuts, no solution" << endl;
  }
}