#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int wind[11][101];
int memo[101][11];
int INF = 1e9;
int M;
int f(int m, int h) {
	if (h < 0 or h > 9) return INF;
	if (m == M) {
		if (h == 0) return 0;
		return INF;
	}
	if (memo[m][h] != -1) return memo[m][h];
	int &ans = memo[m][h];
	ans = -wind[h][m] + min(f(m+1, h)+30, min(f(m+1, h-1)+20, f(m+1, h+1)+60));
	return ans;
}

int main() {
	int T; cin >> T;
	while (T--) {
		memset(memo, -1, sizeof memo);
		cin >> M; M/=100;
		for (int i = 9; i >= 0; --i) for (int j = 0; j < M; ++j)
			cin >> wind[i][j];
		cout << f(0,0) << endl << endl;
	}
}