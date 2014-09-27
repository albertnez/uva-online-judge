#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxp = 100;
const int maxc = 250;
const int inf = 1e9;
int memo[maxp][maxc*4];
int c[maxp];
int N, C;


int f(int n, int sum) {
  if (n == N) {
    if (sum >= C) return 0;
    return inf;
  }
  if (sum > C+maxc) return inf;
  
  int &ans = memo[n][sum];
  if (ans != -1) return ans;
  return ans = min(f(n+1, sum), f(n+1, sum+c[n])+c[n]);
  
}

int main() {
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  while (T--) {
    memset(memo, -1, sizeof memo);
    cin >> C; C/=10;
    cin >> N;
    for (int i = 0; i < N; ++i) {
      cin >> c[i];
      c[i]/=10;
    }
    int ans = f(0, 0);
    if (ans == inf) cout << "NO SOLUTION" << endl;
    else cout << ans*10 << endl;
  }
}