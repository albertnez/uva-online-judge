#include <iostream>
using namespace std;
int main() {
	int T, ncase = 0; cin >> T;
	while (T--) {
		unsigned long long n; cin >> n;
		n = (n*(n-1))/2;
		if (n&1) cout << "Case " << ++ncase << ": " << n << '/' << 2 << endl;
		else cout << "Case " << ++ncase << ": " << n/2 << endl;
	}
}