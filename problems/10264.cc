#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<int> vi;

int main() {
	int n;
	while (cin >> n) {
		int maxim = 0;
		vi v((1<<n), 0);
		for (int i = 0; i < (1<<n); ++i) {
			int k;
			cin >> k;
			for (int j = 0; j < n; ++j)
				v[i^(1<<j)] += k;
		}

		for (int i = 0; i < (1<<n); ++i) {
			for (int j = 0; j < n; ++j) {
				maxim = max(maxim, v[i] + v[i^(1<<j)]);
			}
		}
		cout << maxim <<endl;

	}
}