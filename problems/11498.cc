#include <iostream>
using namespace std;
int main() {
	int k;
	while (cin >> k and k != 0) {
		int n, m;
		cin >> n >> m;
		while (k--) {
			int a,b;
			cin >> a >> b;
			if (a == n or b == m) cout << "divisa" << endl;
			else if (a > n and b > m) cout << "NE" << endl;
			else if (a < n and b > m) cout << "NO" << endl;
			else if (a > n and b < m) cout << "SE" << endl;
			else cout << "SO" << endl;
		}
	}
}