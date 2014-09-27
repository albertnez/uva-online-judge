#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adj, radj;
vi visited, S, id;


void dfs1(int u) {
	visited[u] = 1;
	for (int i = 0; i < (int)adj[u].size(); ++i)
		if (!visited[adj[u][i]]) dfs1(adj[u][i]);
	S.push_back(u);
}

void dfs2(int u, int b) {
	visited[u] = 1;
	id[u] = b;
	for (int i = 0; i < (int)radj[u].size(); ++i)
		if (!visited[radj[u][i]]) dfs2(radj[u][i], b);
}



int main() {
	int cases; scanf("%d", &cases);
	while (cases--) {
		int n, m; scanf("%d %d", &n, &m);
		adj = radj = vvi(n);
		visited.assign(n, 0);
		id.assign(n, 0);
		S.clear();

		while (m--) {
			int a, b;
			scanf("%d %d", &a, &b);
			--a; --b;
			adj[a].push_back(b);
			radj[b].push_back(a);
		}

		for (int i = 0; i < n; ++i)
			if (!visited[i]) 
				dfs1(i);

		int total = 0, nid = 0;
		visited.assign(n, 0);
		for (int i = n-1; i >= 0; --i)
			if (!visited[S[i]]) 
				dfs2(S[i], nid++);


		vi incoming(nid, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < (int)radj[i].size(); ++j) {
				if (id[i] != id[radj[i][j]])
					++incoming[ id[i] ];
			}
		}

		for (int i = 0; i < nid; ++i)
			if (!incoming[i])
				++total;

		//if (cases > 0) printf("\n");
		printf("%d\n", total);
	}
}