#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;

const int di[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dj[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int dfs(int i, int j, const vs& map, vvb& m) {
	int s = 0;
	for (int k = 0; k < 8; ++k) {
		int ti = i+di[k], tj = j+dj[k];
		if (ti >= 0 and ti < map.size() and tj >= 0 and tj < map[0].size() and
		map[ti][tj] == 'W' and !m[ti][tj]) {
			m[ti][tj] = true;
			s += 1 + dfs(ti, tj, map, m);
		}
	}
	return s;
}

int main() {
	int ncases; cin >> ncases;
	string s;
	getline(cin,s);
	getline(cin,s);
	int cases = ncases;
	for (int cases = 0; cases < ncases; ++cases) {
		if (cases > 0) cout << endl;
		vs map;
		while(getline(cin,s) and (s[0] == 'L' or s[0] == 'W'))
			map.push_back(s);
		do {
			istringstream ss(s);
			int i, j;
			ss >> i >> j; --i; --j;
			vvb m(map.size(), vb(map[0].size(), false));
			m[i][j] = true;
			if (map[i][j] == 'W') cout << 1 + dfs(i,j,map,m) << endl;
			else cout << 0 << endl;
		} while (getline(cin,s) and s != "");
	}
}