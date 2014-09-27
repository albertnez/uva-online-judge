#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> Vii;
typedef vector<int> Vi;
typedef vector<Vi> Mi;


const int INF = 1e9;

int di[4] = {0, -1, 0, 1};
int dj[4] = {1, 0, -1, 0};

const int n = 2005;

int main() {
	int m1, m2;
	while (scanf("%d", &m1), m1) {
		queue<ii> q;
		Mi dist(n, Vi(n, INF));
		for (int i = 0; i < m1; ++i) {
			ii a; scanf("%d %d", &a.first, &a.second);
			q.push(a);
			dist[a.first][a.second] = 0;
		}
		scanf("%d", &m2);
		for (int i = 0; i < m2; ++i) {
			ii a; scanf("%d %d", &a.first, &a.second);
			dist[a.first][a.second] = -1;
		}

		int mindist = INF;
		while (!q.empty() and mindist == INF) {
			ii u = q.front(); q.pop();

			for (int i = 0; i < 4; ++i) {
				int ti = u.first+di[i], tj = u.second+dj[i];
				if (ti >= 0 and ti < n and tj >= 0 and tj < n) {
					if (dist[ti][tj] == -1) mindist = dist[u.first][u.second]+1;
					else {
						if (dist[u.first][u.second]+1 < dist[ti][tj]) {
							q.push(ii(ti,tj));
							dist[ti][tj] = dist[u.first][u.second]+1;
						}
					}
				}
			}
		}
		printf("%d\n", mindist);
	}
}