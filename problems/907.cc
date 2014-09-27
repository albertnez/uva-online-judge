#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef vector<int> Vi;

Vi acumd;

const int INF = 1e9;

int memo[601][301];

int N, K;
int f(int n, int k) {
  if (memo[n][k] != -1) return memo[n][k];
  int ans = INF;
  if (k > 0) {
    for (int i = n+1; i < N+1; ++i) {
      ans = min(ans, max(acumd[i]-acumd[n],f(i, k-1)));
    }
  }
  ans = min(ans, acumd[N+1]-acumd[n]);
  return memo[n][k] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  while (cin >> N >> K) {
    memset(memo, -1, sizeof memo);
    acumd.assign(N+2, 0);
    for (int i = 1; i < N+2; ++i) {
      cin >> acumd[i];
      if (i > 0) acumd[i] += acumd[i-1];
    }
      
    cout << f(0, K) << endl;
  }
}