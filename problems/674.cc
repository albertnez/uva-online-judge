#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int coins[5] = {50, 25, 10, 5, 1};

int memo[6][7500];

int ways(int type, int value) {
	if (value == 0) return 1;
	if (value < 0 or type >= 5) return 0;
	if (memo[type][value] != -1) return memo[type][value];
	return memo[type][value] = ways(type+1, value) + ways(type, value-coins[type]);
}

int main() {
	int n;
	memset(memo, -1, sizeof memo);
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", ways(0,n));
	}
}