#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> Vi;
int main() {
	int n, d, r;
	while (cin >> n >> d >> r and (n|d|r)) {
		Vi a(n), b(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		for (int i = 0; i < n; ++i)
			cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int t = 0;
		for (int i = 0; i < n; ++i)
			t += max(0, a[i]+b[n-i-1]-d);
		cout << t*r << endl;
	}
}