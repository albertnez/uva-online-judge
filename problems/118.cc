#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int di[4] = {0, 1, 0, -1};
int dj[4] = {1, 0, -1, 0};
string so = "ENWS";

int main() {
	int n, m;
	cin >> n >> m;
	vvi map(m+1, vi(n+1, 0));
	int i, j;
	while (cin >> j >> i) {
		int o;
		char c; cin >> c;
		if (c == 'E') o = 0;
		else if (c == 'N') o = 1;
		else if (c == 'W') o = 2;
		else o = 3;

		string op; cin >> op;

		bool lost = false;
		for (int t = 0; t < op.size() and !lost; ++t) {
			if (op[t] == 'F') {
				if (i+di[o] > m or i+di[o] < 0 or j+dj[o] < 0 or j+dj[o] > n) {
					if (map[i][j] == 0 and !lost) {
						map[i][j] = 1;
						lost = true;
					}
				}
				else {
					i += di[o];
					j += dj[o];
				}
			}
			else if (op[t] == 'L') {
				o = (o+1)%4;
			}
			else o = (o+3)%4;
		}

		cout << j << ' ' << i << ' ' << so[o] << (lost? " LOST" : "") << endl;
	}
}