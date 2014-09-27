#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n and n) {
		bool nnz = false;
		for (int i = 0; i < n; ++i) {
			int k; cin >> k;
			if (k) {
				if (nnz) cout << ' ';
				else nnz = true;
				cout << k;
			}
		}
		if (!nnz) cout << 0 << endl;
		else cout << endl;
	
	}
}