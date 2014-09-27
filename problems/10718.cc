#include <iostream>
using namespace std;
int main() {
	unsigned int n, l, u;
	while (cin >> n >> l >> u) {
		unsigned int sum = 0;
		for (int i = 31; i >= 0; --i) {
			unsigned int x = 1<<i;
			if (((n&x) == 0 and sum+x <= u) or (sum+x-1 < l))
				sum += x;
		}
		cout << sum << endl;
	}
}