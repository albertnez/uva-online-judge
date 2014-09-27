#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<string> Vs;
typedef pair<int,int> ii;
const int INF = 1e9;
const int di[4] = {0, -1, 0, 1}, dj[4] = {1, 0, -1, 0};

int main() {
  int n;
  while (cin >> n) {
    Vs m(n);
    for (int i = 0; i < n; ++i)
      cin >> m[i];

    
    int sol = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
      if (m[i][j] == '1') {
	queue<ii> q;
	Mi dist(n, Vi(n, INF));
	dist[i][j] = 0;
	q.push(ii(i, j));
	bool found = false;
	while (!q.empty() and !found) {
	  ii u = q.front(); q.pop();
	  for (int k = 0; k < 4; ++k) {
	    int ti = u.first+di[k], tj = u.second+dj[k];
	    if (ti >= 0 and ti < n and tj >= 0 and tj < n and dist[ti][tj] == INF) {
	      dist[ti][tj] = dist[u.first][u.second]+1;
	      if (m[ti][tj] == '3') {
		found = true;
		sol = max(sol, dist[ti][tj]);
	      }
	      else {
		q.push(ii(ti,tj));
	} } } }
      }
    }
    cout << sol << endl;
  }
}