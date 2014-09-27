#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

int N, K, M;
ll memo[55][55][55];

ll f(int n, int k) {
	if (k == 0) {
		if (n == 0) return 1;
		return 0;
	}
	if (n < 0) return 0;
	if (memo[n][k][M] != -1) return memo[n][k][M];
	ll ans = 0;
	for (int i = 1; i <= M; ++i)
		ans += f(n-i, k-1);
	return memo[n][k][M] = ans;
}

int main() {
	memset(memo, -1, sizeof memo);
	while (cin >> N >> K >> M)
		cout << f(N,K) << endl;
}