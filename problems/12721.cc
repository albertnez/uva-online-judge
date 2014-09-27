#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
Mi mult(26), cost(26);

const int maxn = 101;
int memo[maxn][maxn];

const int INF = 1e9;

string S;
int N;
int B;

int ctoi(char c) { return c-'a'; }

int f(int n, int k) {
  if (k > B) return INF;
  if (n >= N) {
    if (k == B) return 0;
    return INF;
  }
  
  if (memo[n][k] != -1) return memo[n][k];
  
  int ans = INF;
  int c = 0;
  int l = ctoi(S[n]);
  for (int i = 0; i < mult[l].size(); ++i) {
    if (((k+1)%mult[l][i]) == 0)
      c += ((k+1)/mult[l][i])*cost[l][i];
  }
  ans = min(f(n+1, k), f(n+1, k+1) + c);
  return memo[n][k] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    memset(memo, -1, sizeof memo);
    
    cin >> S >> B;
    N = S.size();
    for (int i = 0; i < 26; ++i) {
      int q; cin >> q;
      mult[i] = cost[i] = Vi(q);
      for (int j = 0; j < q; ++j)
        cin >> mult[i][j] >> cost[i][j];
    }
    
    int sol = f(0, 0);
    cout << "Case #" << ++ncase << ": " << sol << endl;
  }
}