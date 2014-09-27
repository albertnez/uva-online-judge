#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxb = 11;
const int maxn = 128;

int memo[1<<maxb][1<<maxb];
int data[maxn];

int n, b;

const int inf = 1e9;

int readnum(istream &is) {
  string s;
  is >> s;
  int ans = 0;
  for (int i = 0; i < int(s.size()); ++i) {
    ans <<= 1;
    ans += (s[i] == '1');
  }
  return ans;
}

int f(int mask, int ans) {
  if (memo[mask][ans] != -1) return memo[mask][ans];
  int count = 0;
  for (int i = 0; i < n; ++i)
    if ((data[i]&mask) == ans)
      ++count;
  if (count == 1) return memo[mask][ans] = 0;
  
  int &sol = memo[mask][ans] = inf;
  for (int i = 0; i < b; ++i) if ((mask&(1<<i)) == 0) {
    int nmask = mask|(1<<i);
    int nans = ans|(1<<i);
    sol = min(sol, 1+ max(f(nmask, nans), f(nmask, ans)));
  }
  return sol;
}

int main() {
  while (cin >> b >> n and (b|n)) {
    memset(memo, -1, sizeof memo);
    for (int i = 0; i < n; ++i)
      data[i] = readnum(cin);
      
    cout << f(0,0) << endl;
  }
}