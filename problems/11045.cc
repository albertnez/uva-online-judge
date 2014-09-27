#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;

Mi res;
const int INF = 1e9;
int f;
Vi p;
int s, t;

void augment(int v, int minEdge) {
	if (v == s) 
		f = minEdge;
	else if (p[v] != -1) {
		int u = p[v];
		augment(u, min(minEdge, res[u][v]));
		res[u][v] -= f;
		res[v][u] += f;
	}
}

int fn(string st) {
	if (st == "XXL") return 0;
	if (st == "XL") return 1;
	if (st == "L") return 2;
	if (st == "M") return 3;
	if (st == "S") return 4;
	if (st == "XS") return 5;
}

int main() {
	int T; cin >> T;
	while (T--) {
		int n, m; 
		cin >> n >> m;
		int each = n/6;
		int total = 8+m;
		res = Mi (total, Vi(total, 0));
		p = Vi(total, -1);

		// source to tshirt 
		for (int i = 1; i <= 6; ++i)
			res[0][i] = each;

		// people to sink
		for (int j = 7; j < total-1; ++j)
			res[j][total-1] = 1;

		// tshirt to people
		for (int i = 7; i < total-1; ++i) {
			string a,b; cin >> a >> b;
			int x = fn(a), y = fn(b);
			res[1+x][i] = 1;
			res[1+y][i] = 1;
		}

		s = 0;
		t = total-1;

		int mf = 0;
		while (1) {
			queue<int> q;
			Vi dist(total, INF);
			dist[s] = 0;
			q.push(s);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				for (int v = 0; v < total; ++v) {
					if (res[u][v] > 0 and dist[v] == INF) {
						dist[v] = dist[u]+1;
						p[v] = u;
						q.push(v);
					}
				}
			}

			augment(t, INF);
			if (f == 0) break;
			mf += f;
		}
		if (mf == m) cout << "YES" << endl;
		else cout << "NO" << endl;


	}
}