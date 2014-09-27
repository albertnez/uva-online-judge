#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;

const int maxn = 201;
const int mxv = (unsigned(1<<31))-1;

ll dp[maxn];

string s;

ll stoi(int i, int j) {
  if (s[i] == '0') return 0;
  ll n = 0;
  for (int k = i; k < j; ++k) {
    n *= 10;
    n += s[k]-'0';
  }
  return n;
}

ll exp(int e) {
  ll n = 1;
  while (e--) n*= 10;
  return n;
}

int main() {
  int T; cin >> T;
  getline(cin,s);
  while (T--) {
    getline(cin,s);
    dp[0] = 0;
    for (int n = 1; n <= int(s.size()); ++n) {
      dp[n] = 0;
      ll num = 0;
      for (int k = 1; k <= 10 and k <= n; ++k) {
        num += (s[n-k]-'0')*exp(k-1);
        if (num > mxv) break;
        dp[n] = max(dp[n], num + dp[n-k]);
      }
    }
    cout << dp[s.size()] << endl;
  }
}