#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long ll;
int N = 11;
int coins[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
ll memo[15][30010];
ll f(int type, int val) {
	if (val == 0) return 1;
	if (type == N or val < 0) return 0;
	if (memo[type][val] != -1) return memo[type][val];
	return memo[type][val] = f(type+1, val) + f(type, val-coins[type]);
}

int main() {
	memset(memo, -1, sizeof memo);
	double x; int val;
	while (scanf("%lf", &x) and (val = x*100+0.1)) {
		printf("%6.2f%17llu\n", x, f(0, val));
	}

}