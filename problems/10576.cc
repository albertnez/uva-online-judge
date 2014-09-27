#include <iostream>
#include <vector>
using namespace std;
int s, d, sol;

void bt(int n, int m) {
  if (n == 12) {
    int sum = 0;
    for (int i = 0; i < 12; ++i)
      sum += (m&(1<<i) ? s : -d);
    sol = max(sol, sum);
  }
  else {
    if (n >= 4) {
      int sum = 0;
      for (int i = 1; i < 5; ++i)
        sum += (m&(1<<(n-i)) ? s : -d);
      
      if (sum-d < 0) bt(n+1, m);
      if (sum+s < 0)
        bt(n+1, m|(1<<n));  
    }
    else {
      bt(n+1, m);
      bt(n+1, m|(1<<n));
    }
  }
}

int main() {
  while (cin >> s >> d) {
    sol = 0;
    bt(0, 0);
    if (sol) cout << sol << endl;
    else cout << "Deficit" << endl;
  }
}