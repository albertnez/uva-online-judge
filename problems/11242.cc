#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> Vi;
typedef vector<double> Vd;

int main() {
	int f, r;
	while (cin >> f and f) {
		cin >> r;
		Vi vf(f), vr(r);
		Vd vd(f*r);
		for (int i = 0; i < f; ++i) cin >> vf[i];
		for (int i = 0; i < r; ++i) cin >> vr[i];
		for (int i = 0; i < f; ++i) for (int j = 0; j < r; ++j)
			vd[i*r+j] = double(vf[i]) / double(vr[j]);
		sort(vd.begin(), vd.end());
		double maxim = 0;
		for (int i = 0; i < f*r-1; ++i)
			maxim = max(maxim, vd[i+1]/vd[i]);

		cout.precision(2);
		cout << fixed << maxim << endl;
	}
}