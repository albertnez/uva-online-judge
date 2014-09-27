#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef vector<double> Vd;
typedef vector<Vd> Md;
typedef pair<int,int> ii;
typedef vector<ii> Vii;
typedef vector<int> Vi;

int N;
Md dists(8, Vd(8, 0));
Vii pos(8);

double minDist = 1e9;
Vi minOrder;

void f(int n, int vis, double d, Vi& order) {
	if (vis == (1<<N)-1) {
		if (d < minDist) {
			minDist = d;
			minOrder = order;
		}
	}
	else {
		for (int i = 0; i < N; ++i) {
			if (!((1<<i)&vis)) {
				order.push_back(i);
				f(i, vis|(1<<i), d+dists[n][i], order);
				order.pop_back();
			}
		}
	}
}

int main() {
	int ncase = 0;
	while (scanf("%d", &N), N) {
		minDist = 1e9;
		for (int i = 0; i < N; ++i) {
			scanf("%d %d", &pos[i].first, &pos[i].second);
			for (int j = 0; j < i; ++j) {
				dists[i][j] = dists[j][i] = hypot(pos[i].first-pos[j].first, pos[i].second - pos[j].second);
			}
		}

		Vi v(1);
		for (int i = 0; i < N; ++i) {
			v[0] = i;
			f(i, 1<<i, 0, v);
		}

		double total = 0;
		printf("**********************************************************\nNetwork #%d\n", ++ncase);
		for (int i = 0; i < int(minOrder.size())-1; ++i) {
			int u = minOrder[i], v = minOrder[i+1];
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", pos[u].first, pos[u].second, pos[v].first, pos[v].second, dists[u][v]+16.0);
			total += dists[u][v]+16.0;
		}
		printf("Number of feet of cable required is %.2lf.\n", total);
	}
}