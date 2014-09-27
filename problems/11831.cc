#include <iostream>
#include <vector>
using namespace std;
typedef vector<char> vc;
typedef vector<vc> vvc;


int di[4] = {0, -1, 0, 1};
int dj[4] = {1, 0, -1, 0};

int main() {
	int n, m, s;
	while (cin >> n >> m >> s and (n and m and s)) {
		int score = 0;
		vvc map(n, vc(m));
		int pi, pj, o;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				char c; cin >> c;
				map[i][j] = c;
				if (c != '.' and c != '#' and c != '*') {
					pi = i; pj = j;
					if (map[i][j] == 'N') o = 1;
					else if (map[i][j] == 'O') o = 2;
					else if (map[i][j] == 'S') o = 3;
					else if (map[i][j] == 'L') o = 0;
				}
			}
		}
		while (s--) {
			char op; cin >> op;
			if (op == 'D') o = (o+3)%4;
			else if (op == 'E') o = (o+1)%4;
			else {
				int ti = pi+di[o], tj = pj+dj[o];
				if (ti < 0 or ti >= n or tj < 0 or tj >= m or map[ti][tj] == '#') continue;
				if (map[ti][tj] == '*') {
					map[ti][tj] = '.';
					++score;
				}
				pi = ti;
				pj = tj;
			}
		}
		cout << score << endl;
	}


}