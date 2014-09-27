#include <iostream>
#include <map>
#include <vector>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adj;
vi num, low, visited;
vector<string> vs;
stack<int> S;
int dfscount;

void scc(int u) {
	low[u] = num[u] = dfscount++;
	S.push(u);
	visited[u] = 1;
	for (int i = 0; i < adj[u].size(); ++i) {
		int v = adj[u][i];
		if (num[v] < 0) 
			scc(v);
		if (visited[v])
			low[u] = min(low[u], low[v]);
	}

	if (low[u] == num[u]) {
		while (1) {
			int v = S.top(); S.pop(); visited[v] = 0;
			cout << vs[v];
			if (u != v) cout << ", ";
			else break;
		}
		cout << endl;
	}
}

int main() {
	int n, m;
	int cases = 0;
	while (cin >> n >> m and n and m) {
		num.assign(n, -1); low.assign(n, -1); visited.assign(n, 0);
		adj = vvi(n);
		vs = vector<string>(n);
		map<string,int> msi;
		int namecount = 0;
		dfscount = 0;
		while (m--) {
			string sa, sb;
			cin >> sa >> sb;
			if (msi.find(sa) == msi.end()) {
				msi[sa] = namecount;
				vs[namecount] = sa;
				namecount++;
			}
			if (msi.find(sb) == msi.end()) {
				msi[sb] = namecount;
				vs[namecount] = sb;
				namecount++;
			}
			adj[msi[sa]].push_back(msi[sb]);
		}



		if (cases) cout << endl;
		cout << "Calling circles for data set " << ++cases << ':' << endl;
		for (int i = 0; i < n; ++i) {
			if (num[i] < 0)
				scc(i);
		}
	}
}