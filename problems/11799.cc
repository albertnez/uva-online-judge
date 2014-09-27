#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		int max = 0, n;
		cin >> n;
		while (n--) {
			int k;
			cin >> k;
			if (k > max) max = k;
		}
		cout << "Case " << i << ": " << max << endl;
	}
}