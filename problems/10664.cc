#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

int w[20];
int N;

int memo[20][205];

int f(int n, int remw) {
	if (remw == 0) return 1;
	if (n == N or remw < 0) return 0;
	if (memo[n][remw] != -1) return memo[n][remw];
	return memo[n][remw] = f(n+1, remw - w[n]) | f(n+1, remw);
}

int main() {
	int cases; cin >> cases; cin.ignore();
	while (cases--) {
		memset(memo, -1, sizeof memo);
		string s;
		getline(cin,s);
		istringstream ss(s);
		N = 0;
		int sum = 0;
		while (ss >>w[N])
			sum += w[N++];
		
		cout << ((sum%2 == 0 and f(0,sum/2)) ? "YES" : "NO") << endl;
	}
}