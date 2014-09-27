#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<bool> vb;
typedef map<string,int> mpi;

int main() {
	int n, cases = 0;
	while (cin >> n) {
		mpi wtoi;
		vector<string> itow(n); 
		for (int i = 0; i < n; ++i) {
			string s; cin >> s;
			wtoi[s] = n-i-1;
			itow[n-i-1] = s;
		}
		
		int m; cin >> m;
		vii adj(n);
		vi degree(n, 0);
		while (m--) {
			string a, b; cin >> a >> b;
			adj[wtoi[a]].push_back(wtoi[b]);		
			++degree[wtoi[b]];
		}
	
		priority_queue<int> pq;
		for (int i = 0; i < n; ++i)
			if (degree[i] == 0) pq.push(i);
		

		cout << "Case #" << ++cases << ": Dilbert should drink beverages in this order:";
		while (!pq.empty()) {
			int vert = pq.top(); pq.pop();
			for (int i = 0; i < int(adj[vert].size()); ++i) 
				if (!(--degree[adj[vert][i]])) pq.push(adj[vert][i]);
			cout << ' ' << itow[vert];		
		}
		cout << '.' << endl << endl;
	}
}
