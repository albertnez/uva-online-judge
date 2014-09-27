#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> ii;

const int MAX = 35;

int N, W;
int depth[MAX], gold[MAX];

ii memo[MAX][1005];
int chosen[MAX];

ii f(int n, int t) {
	if (n == N or t <= 0) return ii(0, 0);
	if (memo[n][t].first != -1) return memo[n][t];

	ii ans = f(n+1, t);
	if (depth[n]*W*3 <= t) {
		ii tmp = f(n+1, t-depth[n]*W*3);
		tmp.first += gold[n];
		tmp.second |= 1<<n;

		if (tmp.first > ans.first) ans = tmp;
	}

	memo[n][t] = ans;
	return ans;
}

const int INF = 1e9;
int main() {
	int t;
	bool first = true;
	while (cin >> t >> W) {
		if (first) first = false;
		else cout << endl;

		for (int i = 0; i < MAX; ++i) for (int j = 0; j < 1005; ++j) memo[i][j].first = -1;
		for (int i = 0; i < MAX; ++i) chosen[i] = 0;
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> depth[i] >> gold[i];

		ii ans = f(0, t);
		cout << ans.first << endl;
		int n = 0;
		for (int i = 0; i < 32; ++i)
			if (ans.second & 1<<i) ++n;
		cout << n << endl;
		for (int i = 0; i < 32; ++i)
			if (ans.second & 1<<i)
				cout << depth[i] << ' ' << gold[i] << endl;
	}
}