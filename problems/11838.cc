#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adj;
vi num, low, visited;
stack<int> S;
int count, total;

void f(int u) {
	num[u] = low[u] = count++;
	S.push(u);
	visited[u] = 1;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (num[v] < 0)
			f(v);
		if (visited[v])
			low[u] = min(low[u], low[v]);
	}

	if (low[u] == num[u]) {
		++total;
		while (1) {
			int v = S.top();
			visited[v] = 0;
			S.pop();
			if (u == v) break;
		}
	}
}



int main() {
	int n, m;
	while (cin >> n >> m and n and m) {
		count = total = 0;
		num = low = vi(n, -1); visited.assign(n, 0);
		adj = vvi(n);
		while (m--) {
			int a,b,p; cin >> a >> b >> p;
			--a; --b;
			adj[a].push_back(b);
			if (p == 2) adj[b].push_back(a);
		}

		for (int i = 0; i < n; ++i) {
			if (num[i] < 0)
				f(i);
		}

		if (total == 1) cout << 1 << endl;
		else cout << 0 << endl;
	}
}