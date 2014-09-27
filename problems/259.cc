#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <queue>
using namespace std;
typedef vector<int> Vi;
typedef vector<int> Mi;


const int MAX_V = 38;
int res[MAX_V][MAX_V], mf, f, s, t;
Vi p(MAX_V);
int INF = 1e9;


void augment(int v, int minEdge) {
	if (v == s) {
		f = minEdge;
		return;
	}
	else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}


int main() {
	string op;
	s = 0;
	t = 37;
	while (getline(cin,op)) {
		int total = 0;
		memset(res, 0, sizeof res);
		for (int i = 27; i <= 36; ++i)
			res[i][37] = 1;

		do {
			istringstream ss(op);
			char c; 
			int n, app;
			ss >> c >> n;
			app = c-'A'+1;
			res[0][app] = n;
			total += n;
			while (ss>>c and c!= '\'') {
				res[app][c-'0'+27] = INF;
			}
		} while (getline(cin, op) and op != "");



		mf = 0;
		while (1) {
			f = 0;
			Vi dist(MAX_V, INF);
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				if (u == t) break; //stop BFS
				for (int v = 0; v < MAX_V; v++)
					if (res[u][v] > 0 && dist[v] == INF) {
						dist[v] = dist[u]+1;
						q.push(v);
						p[v] = u;
					}
			}

			augment(t, INF); //find the min edge weight 'f' in this path
			if (f == 0) break;
			mf += f;
		}

		if (total == mf) { //print de solution
			for (int i = 27; i <= 36; ++i) {
				int j;
				for (j = 1; j < 27; ++j) {
					if (res[i][j] == 1) {
						cout << char('A'+(j-1));
						break;
					}
				}
				if (res[i][j] != 1) cout << '_';
			}
			cout << endl;

		}
		else cout << "!" << endl;
	}

}