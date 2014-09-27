#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <sstream>
#include <map>
using namespace std;

typedef vector<int> Vi;
typedef vector<Vi> Mi;

bool dif(const string& a, const string& b) {
	if (a.size() != b.size()) return false;
	int x = 0;
	for (int i = 0; i < a.size(); ++i)
		x += a[i] != b[i];
	return (x <= 1);
}	

int main() {
	int cases; cin >> cases;
	for (int ncases = 0; ncases < cases; ++ncases) {
		string s;
		vector<string> words;
		Mi adj;
		map<string,int> msi;
		int i = 0;
		while (cin >> s and s != "*") {
			adj.push_back(Vi());
			words.push_back(s);	
			msi[s] = i;
			for (int j = 0; j < i; ++j) {
				if (dif(s, words[j])) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
			++i;
		}

		getline(cin, s);
		if (ncases) cout << endl;
		while (getline(cin, s) and s != "") {
			istringstream ss(s);
			string a, b;
			ss >> a >> b;
			int destination = msi[b];
			Vi dist(i, 0);
			queue<int> q;
			q.push(msi[a]);
			bool run = true;
			while (!q.empty() and run) {
				int u = q.front(); q.pop();
				for (int j = 0; j < int(adj[u].size()); ++j) {
					int v = adj[u][j];
					if (!dist[v]) {
						dist[v] = dist[u]+1;
						if (v == destination) run = false;
						else q.push(v);
					}
				}
			}
			cout << a << ' ' << b << ' ' << dist[destination] << endl;
		}
	}
}
