#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> Vi;

int main() {
	int n;
	bool first =true;
	while (cin >> n) {
		Vi v(n);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		int m; cin >> m;
		sort(v.begin(), v.end());
		int a,b;
		bool found = false;
		for (int i = 0; i < n; ++i) {
			int x = v[i];
			Vi::iterator it = lower_bound(v.begin(), v.end(), m-x);
			if (it == v.begin()+i) continue;
			int y = *it;
			if (x+y == m and (!found or abs(x-y) < abs(a-b))) {
				a = x;
				b = y;
				found = true;
			}
		}
		cout << "Peter should buy books whose prices are " << a << " and " << b << '.' << endl << endl;;
	}
}