#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> Vi;
typedef vector<ll> Vll;
int main() {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		Vi coins(n);
		for (int i = 0; i < n; ++i)
			cin >> coins[i];

		int sum = 1;
		int t = 1;
		for (int i = 1; i < n-1; ++i) {
			if (sum+coins[i] < coins[i+1]) {
				sum += coins[i];
				++t;
			}
		}
		if (n > 1) ++t;
		cout << t << endl;
	}
}