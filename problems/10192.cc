#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 105;
const int inf = 1e9;
int t[maxn][maxn];

int main() {
  int ncase = 0;
  string a, b;
  while (getline(cin,a) and a != "#") {
    getline(cin, b);
    memset(t, 0, sizeof t);
    int n = a.size();
    int m = b.size();
    
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      t[i][j] = max(t[i][j], t[i-1][j-1] + (a[i-1] == b[j-1] ? 1 : -inf));
      t[i][j] = max(t[i][j], t[i-1][j]);
      t[i][j] = max(t[i][j], t[i][j-1]);
    }
    cout << "Case #" << ++ncase << ": you can visit at most " << t[n][m] << " cities." << endl;
  }
}