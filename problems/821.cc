#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;

int n = 105;
int INF = 1e9;

int main() {
	int a,b;
	int ncase = 0;
	vector<bool> used;
	Vi v;
	while (scanf("%d %d", &a, &b), (a||b)) {
		used.assign(n, false);
		v.assign(0, 0);
		if (!used[a]) {
			used[a] = true;
			v.push_back(a);
		}
		if (!used[b]) {
			used[b] = true;
			v.push_back(b);
		}
		Mi adj(n, Vi(n, INF));
		adj[a][b] = 1;
		while (scanf("%d %d", &a, &b), (a||b)) {
			adj[a][b] = 1;
			if (!used[a]) {
				used[a] = true;
				v.push_back(a);
			}
			if (!used[b]) {
				used[b] = true;
				v.push_back(b);
			}
		}

		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j) 
					adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);

		int num = v.size();
		int total = 0;
		for (int i = 0; i < num; ++i) {
			for (int j = 0; j < num; ++j) {
				if (i == j) continue;
				total += adj[v[i]][v[j]];
			}
		}
		printf("Case %d: average length between pages = %.3lf clicks\n", ++ncase, double(total)/(num*(num-1)));
		
	}
}