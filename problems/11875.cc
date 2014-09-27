#include <iostream>
using namespace std;

int main() {
	int T; cin >> T;
	for (int ncas = 1; ncas <= T; ++ncas) {
		int n; cin >> n;
		int sol, k;
		for (int i = 0; i < n; ++i)
			cin >> (i == n/2 ? sol : k);
		cout << "Case " << ncas << ": " << sol << endl;
	}
}