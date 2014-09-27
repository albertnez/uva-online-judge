#include <iostream>
#include <vector>

using namespace std;
typedef vector<string> Vs;
typedef vector<int> Vi;

int main() {
	int cases; cin >> cases;
	while (cases--) {
		int n; cin >> n;
		Vs names(n);
		Vi mi(n), ma(n);
		for (int i = 0; i < n; ++i) 
			cin >> names[i] >> mi[i] >> ma[i];
		
		int q; cin >> q;
		while (q--) {
			int k; cin >> k;
			int ind = -1;
			for (int i = 0; i < n; ++i) {
				if (mi[i] <= k and ma[i] >= k) {
					if (ind != -1) {
						ind = -1;
						break;
					}
					ind = i;
				}
			}
			if (ind == -1) cout << "UNDETERMINED" << endl;
			else cout << names[ind] << endl;
		}
		if (cases) cout << endl;	
	}
}