#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<string> Vs;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef pair<int,int> ii;
const int INF = 1e9;


Vs map;
Mi dist;
int ex, bl, al;
int n, m;

void dfs(int i, int j, int q) {
	if (i >= 0 and i < n and j >= 0 and j < m) {
		if (dist[i][j] == INF) {
			dist[i][j] = q;
			if (map[i][j] == 'N') dfs(i-1, j, q+1);
			else if (map[i][j] == 'S') dfs(i+1, j, q+1);
			else if (map[i][j] == 'W') dfs(i, j-1, q+1);
			else dfs(i, j+1, q+1);
		}
		else {
			ex = -1;
			bl = dist[i][j];
			al = q-bl;
		}
	}
	else
		ex = q;
}

int main() {
	int s;
	while (cin >> n >> m >> s and (n|m|s)) {
		--s;
		map = Vs(n);
		dist = Mi(n, Vi(m, INF));
		for (int i = 0; i < n; ++i)
			cin >> map[i];
		dfs(0, s, 0);

		if (ex >= 0) cout << ex << " step(s) to exit" << endl;
		else cout << bl << " step(s) before a loop of " << al << " step(s)" << endl;

	}
}