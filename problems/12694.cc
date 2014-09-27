#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> II;
typedef vector<II> VII;
VII v;

vector<int> start, end;

int maxn = 0;
int l;
const int maxp = 10;
void f(int p, int n) {
  maxn = max(maxn, n);
  for (int i = 0; i < l; ++i)
    if (start[i] >= p)
      f(end[i], n+1);
  

}

int main() {
  int T; cin >> T;
  while (T--) {
    start.assign(20, 0);
    end.assign(20, 0);
    l = 0;
    maxn = 0;
    int a, b;
    while (cin >> a >> b and (a|b)) {
      start[l] = a;
      end[l] = b;
      ++l;
    }
    f(0, 0);
    cout << maxn << endl;
  }
}