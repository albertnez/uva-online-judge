#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n;
	cin >> n;
	while (n--) {
		char c;
		int n,m;
		cin >> c >> n >> m;
		if (c == 'r') cout << min(n,m) << endl;
		else if (c == 'k') cout << max(n/2*m,m/2*n) << endl;
		else if (c == 'K') cout << ((n+1)/2)*((m+1)/2) << endl;
		else if (c == 'Q') {
			if (n == 3 and m == 3) cout << 2 << endl;
			else if (n == 2 and m == 2) cout << 1 << endl;
			else cout << min(n,m) << endl;
		}
	}
}