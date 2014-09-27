#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vi;
int main() {
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    Vi v(10, 0);
    for (int i = 1; i <= n; ++i) {
      int x = i;
      while (x) {
        ++v[x%10];
        x/=10;
      }
    }
    for (int i = 0; i < 10; ++i)
      cout << (i ? " " : "") << v[i];
    cout << endl;
  }
}