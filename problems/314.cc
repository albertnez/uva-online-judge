#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

typedef pair<int,int> Pi;
typedef pair<Pi,int> PPi;

typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<Mi> VMi;

int di[4] = {0, -1, 0, 1};
int dj[4] = {1, 0, -1, 0};

const int INF = 1e9;

int main() {
	int n, m; 
	while (scanf("%d %d", &n, &m), (n|m)) {
		++n; ++m;
		Mi map(n, Vi(m, 0));

		for (int i = 0; i < n-1; ++i)
			for (int j = 0; j < m-1; ++j) {
				
				int k; scanf("%d", &k);
				if (!map[i][j]) map[i][j] = k;
				if (k) {
					map[i+1][j] = 1;
					map[i+1][j+1] = 1;
					map[i][j+1] = 1;
				}
				
				//scanf("%d", &map[i][j]);
			}

		int si, sj; scanf("%d %d", &si, &sj);
		int ei, ej; scanf("%d %d", &ei, &ej);
		int o = 0;
		string s;
		cin >> s;
		// scanf("%s", &s[0]);
		if (s == "north") o = 1;
		else if (s == "west") o = 2;
		else if (s == "south") o = 3;
		//printf("o: %d  %d\n", o, int(s.size()));

		VMi dist(n, Mi(m, Vi(4, INF)));


		dist[si][sj][o] = 0;

		queue<PPi> q;
		q.push(PPi(Pi(si, sj), o));

		int total = -1;
		while (!q.empty()) {
			PPi front = q.front(); q.pop();
			int o = front.second;
			Pi u = front.first;
			int d = dist[u.first][u.second][o];

			if (u.first == ei and u.second == ej) {
				total = d;
				break;
			}

			//turn right + left;

			if (d+1 < dist[u.first][u.second][(o+1)%4]) {
				dist[u.first][u.second][(o+1)%4] = d+1;
				q.push(PPi(Pi(u.first,u.second), (o+1)%4));

			}
			if (d+1 < dist[u.first][u.second][(o+3)%4]) {
	 			dist[u.first][u.second][(o+3)%4] = d+1;
				q.push(PPi(Pi(u.first,u.second), (o+3)%4));

			}

			for (int k = 1; k <= 3; ++k) {
				//for (int i = 0; i < 4; ++i) {
					bool valid = true;
					for (int i = 1; i <= k; ++i) {
						int ti = u.first+di[o]*i, tj = u.second+dj[o]*i;
						if (ti <= 0 or ti >= n-1 or tj <= 0 or tj >= m-1 or map[ti][tj]) valid = false;
					}
					if (valid) {
						int ti = u.first+di[o]*k, tj = u.second+dj[o]*k;
						if (d+1 < dist[ti][tj][o]) {
							dist[ti][tj][o] = d+1;
							q.push(PPi(Pi(ti,tj), o));
						}
					}
				//}
			}
		}
		printf("%d\n", total);
	}
}