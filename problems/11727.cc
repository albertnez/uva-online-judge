#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int c = 1; c <= t; ++c) {
		vector<int> v(3);
		for (int i = 0; i < 3; ++i) cin >> v[i];
		sort(v.begin(),v.end());
		cout << "Case " << c << ": " << v[1] << endl;
	}
}