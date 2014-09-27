#include <iostream>
#include <cstring>
using namespace std;

string s;

const int maxn = 1001;
int memo[maxn][maxn];

int f(int i, int j) {
  if (j < i) return 0;
  if (i== j) return 1;
  if (i+1 == j) return (s[i] == s[j] ? 2 : 1);
  if (memo[i][j] != -1) return memo[i][j];
  
  if (s[i] == s[j]) return memo[i][j] = (2 + f(i+1, j-1));
  return memo[i][j] = max(f(i+1, j), f(i, j-1));
}

int main() {
  int T; cin >> T;
  getline(cin, s);
  while (T--) {
    memset(memo, -1, sizeof memo);
    getline(cin, s);
    cout << f(0, s.size()-1) << endl;
  }
}