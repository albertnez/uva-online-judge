#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

int main() {
	int n, m, cas = 0;
	while (cin >> n >> m and n and m) {
		vii map(n, vi(m, 0));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				char c; cin >> c;
				if (c == '*') {
					map[i][j] = -1;
					for (int ti = i-1; ti <= i+1; ++ti)
						for (int tj = j-1; tj <= j+1; ++tj)
							if (ti >= 0 and ti < n and tj >= 0 and tj < m and map[ti][tj] >= 0) ++map[ti][tj];
				}
			}
		}
		if (cas > 0) cout << endl;
		cout << "Field #" << ++cas << ':' << endl;
		for (int i = 0; i < n; ++i){ 
			for (int j = 0; j < m; ++j) {
				if (map[i][j] >= 0) cout << map[i][j];
				else cout << '*';
			}
			cout << endl;
		}
	}
}