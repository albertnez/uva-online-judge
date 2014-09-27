#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;
typedef pair<double, int> di;
typedef pair<int, double> id;
typedef vector<id> Vid;
typedef vector<Vid> Mid;

typedef pair<int,int> ii;
typedef vector<ii> Vii;

typedef vector<double> Vd;
typedef vector<Vd> Md;

double wspeed = 1000.0/6;
double tspeed = 4000.0/6;


double fd(id a, id b) {
	return hypot(a.first-b.first, a.second-b.second);
}


const int INF = 1e9;

int main() {
	int cases; cin >> cases;
	while (cases--) {
		Vii pos(210);
		Mid adj(210);

		ii s, e;
		cin >> s.first >> s.second >> e.first >> e.second;
		pos[0] = s; pos[1] = e;

		adj[0].push_back( id(1, fd(s,e)/wspeed) );
		adj[1].push_back( id(0, fd(s,e)/wspeed) );

		cin.ignore();
		string line;
		int ind = 2;
		while (getline(cin,line) and line != "") {
			istringstream ss(line);
			ii a;
			ss >> a.first >> a.second;
			pos[ind] = a;

			for (int i = 0; i < ind; ++i) {
				double d = fd(pos[i], a)/wspeed;
				adj[i].push_back(id(ind,d));
				adj[ind].push_back(id(i,d));
			}
			++ind;

			while (ss >> a.first >> a.second and a.first != -1 and a.second != -1) {
				pos[ind] = a;
				double d = fd(pos[ind-1],pos[ind])/tspeed;
				adj[ind].push_back(id(ind-1, d));
				adj[ind-1].push_back(id(ind,d));


				for (int i = 0; i < ind; ++i) {
					double d = fd(pos[i], a)/wspeed;
					adj[i].push_back(id(ind,d));
					adj[ind].push_back(id(i,d));
				}
				++ind;
			}
		}

// printf adj list
		/*
		for (int i = 0; i < ind; ++i) {
			cout << "(" << i << " : " << pos[i].first << ',' << pos[i].second << ")  \t|";
			for (int j = 0; j < adj[i].size(); ++j) {
				cout << "\t(" << adj[i][j].first << "," << adj[i][j].second << ")";
			}
			cout << endl;
		}
*/

		double total = 0;

		Vd dist (210, INF);
		dist[0] = 0;
		priority_queue<di, vector<di>, greater<di> > q;
		q.push(di(0, 0));
		while (!q.empty()) {
			di front = q.top(); q.pop();
			double d = front.first;
			int u = front.second;
			if (u == 1) {
				total = d;
				break;
			}
			if (d > dist[u]) continue;

			for (int i = 0; i < adj[u].size(); ++i) {
				id v = adj[u][i];
				if (d+v.second < dist[v.first]) {
					dist[v.first] = d+v.second;
					q.push(di(dist[v.first], v.first));
				}
			}
		}


		cout << round(total) << endl;
		if (cases) cout << endl;
	}
}