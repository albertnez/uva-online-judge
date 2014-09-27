#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef vector<int> Vi;
Vi v(101);
Vi sol(101);

int N, K;
const int INF = 1e9;
const string tb = "-+/*";


int memo[101][64005];
int f(int n, int k) {
	if (k > 32000 or k < -32000) return INF;
	if (n == N-1 and k == K) return 0;
	if (n == N-1) return INF;
	if (memo[n][k] != -1) return memo[n][k];
	int &ans = memo[n][k];
	int x = v[n+1];
	if ((ans = f(n+1, k-x)) == 0) sol[n] = 0;
	else if ((ans = f(n+1, k+x)) == 0) sol[n] = 1;
	else if (k%x == 0 and x!= 0 and ((ans = f(n+1, k/x)) == 0)) sol[n] = 2;
	else if ((ans = f(n+1, k*x)) == 0) sol[n] = 3;
	return ans;
}

int main() {
	int T; cin >> T;
	while (T--) {
		memset(memo, -1, sizeof memo);
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> v[i];
		cin >> K;
		int ans = f(0, v[0]);
		if (ans) cout << "NO EXPRESSION" << endl;
		else {
			cout << v[0];
			for (int i = 0; i < N-1; ++i)
				cout << tb[sol[i]] << v[i+1];
			cout << '=' << K << endl;
			
		}
	}
}