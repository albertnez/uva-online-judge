#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef pair<int,int> ii;
typedef pair<double, ii> dii;
typedef vector<dii> Vdii;
typedef pair<double,double> dd;
typedef vector<dd> Vdd;

double dist(dd a, dd b) {
	return hypot(a.first-b.first, a.second-b.second);
}

Vi p;
int getp(int a) { return p[a] < 0 ? a : getp(p[a]); }

bool same(int a, int b) {
	return getp(a) == getp(b);
}

void join(int a, int b) {
	if (!same(a,b))
		p[getp(a)] = getp(b);
}

int main() {
	cout.precision(2);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		p.assign(n, -1);
		Vdii edges;
		Vdd pos(n);
		for (int i = 0; i < n; ++i) {
			cin >> pos[i].first >> pos[i].second;
			for (int j = 0; j < i; ++j) 
				edges.push_back(dii(dist(pos[i], pos[j]), ii(i, j)));
		}
		sort(edges.begin(), edges.end());

		double sol = 0;
		
		for (int i = 0; i < edges.size(); ++i) {
			dii x = edges[i];
			if (!same(x.second.first, x.second.second)) {
				join(x.second.first, x.second.second);
				sol += x.first;
			}
		}
		cout << fixed << sol << endl;
		if (T) cout << endl;

	}

}