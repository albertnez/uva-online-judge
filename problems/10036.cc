#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
typedef vector<int> Vi;
Vi v;
int N, K;
int memo[100001][101];

int f(int n, int k) {
	if (n == N-1) 
		return k;
	if (memo[n][k] != -1) return memo[n][k];
	int &ans = memo[n][k];
	ans = f(n+1, (((k+v[n+1])%K)+K)%K);
	if (ans == 0) return ans;
	return ans = f(n+1, (((k-v[n+1])%K)+K)%K);
}

int main() {
	int T; cin >> T;
	while (T--) {
		cin >> N >> K;
		v = Vi(N);
		
		memset(memo, -1, sizeof memo);
		for (int i = 0; i < N; ++i) 
			cin >> v[i];

		int ans = f(0, ((v[0]%K)+K)%K);
		if (!ans) cout << "Divisible" << endl;
		else cout << "Not divisible" << endl;
	}
}