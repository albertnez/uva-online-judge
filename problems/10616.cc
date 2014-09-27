#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

//memo N, M, D
int N, D, M;
int values[205];
ll memo[205][15][25];

ll dp(int n, int m, int r) {
	if (m == M and r == 0)	return 1;
	if (m == M) return 0;
	if (n == N) return 0;

	if (memo[n][m][r] != -1) return memo[n][m][r];
	ll& ans = memo[n][m][r];
	ans = 0;

	ans += dp(n+1, m+1, (r+ (values[n]%D) + D)%D); //take
	if (N-n > M-m) ans += dp(n+1, m, r); //don't take
	return ans;
}
 
int main() {
	int q, ncase = 0;
	while (cin >> N >> q and (N|q)) {
		cout << "SET " << ++ncase << ':' << endl;
		for (int i = 0; i < N; ++i) cin >> values[i];

		for (int i = 0; i < q; ++i) {
			memset(memo, -1, sizeof memo);
			cin >> D >> M;
			cout << "QUERY " << i+1 << ": " << dp(0, 0, 0) << endl;
		}
	}
}