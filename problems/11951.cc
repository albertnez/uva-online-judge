#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ll;
typedef vector<ll> Vll;
typedef vector<Vll> Mll;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<bool> Vb;
typedef vector<Vb> Mb;

int main() {
	int T, ncase=0; cin >> T;
	while (T--) {
		int n, m, k; cin >> n >> m >> k;
		Mll map(n, Vll(m));

		for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (j > 0) map[i][j] += map[i][j-1];
		}
		

		int bestArea = 0, bestCost = 0;
		for (int j = 0; j < m; ++j) for (int r = j; r < m; ++r) {
			int area = 0, cost = 0, start = 0;
			for (int i = 0; i < n; ++i) {
				cost += map[i][r];
				if (j > 0) cost -= map[i][j-1];
				while (cost > k) {
					cost -= map[start][r];
					if (j > 0) cost += map[start][j-1];
					start++;
				}
				area = (r-j+1)*(i-start+1);
				if (area > bestArea or (area == bestArea and cost < bestCost)) {
					bestArea = area;
					bestCost = cost;
				}
			}		
		}
		cout << "Case #" << ++ncase << ": " << bestArea << ' ' << bestCost << endl;
	}
}