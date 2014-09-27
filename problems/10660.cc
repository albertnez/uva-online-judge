#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXN = 25, INF = 1e9, di[4] = {0, -1, 0, 1}, dj[4] = {1, 0, -1, 0};

ii ntoc (int n) { return ii(n/5, n%5); }
int cton (ii n) { return n.first*5 + n.second; }

int main() {
  int T; cin >> T;
  while (T--) {
    Vi map(MAXN, 0);
    int num; cin >> num;
    for (int i = 0; i < num; ++i) {
      ii p;
      cin >> p.first >> p.second;
      cin >> map[cton(p)];
    }	

    ll best = 10000000000000LL;
    int sol = 0;
    
    for (int i = 0; i < MAXN; ++i)
    for (int j = i+1; j < MAXN; ++j)
    for (int k = j+1; k < MAXN; ++k)
    for (int l = k+1; l < MAXN; ++l)
    for (int m = l+1; m < MAXN; ++m) {
      ll t = 0;
      
      queue<int> q;
      Vi dist(MAXN, INF);
      dist[i] = dist[j] = dist[k] = dist[l] = dist[m] = 0;
      q.push(i); q.push(j); q.push(k); q.push(l); q.push(m);
      while (!q.empty()) {
	ii u = ntoc(q.front()); q.pop();
	int nu = cton(u);
	for (int h = 0; h < 4; ++h) {
	  int ti = u.first+di[h], tj = u.second+dj[h];
	  if (ti >= 0 and ti < 5 and tj >= 0 and tj < 5) {
	    int v = cton(ii(ti, tj));
	    if (dist[v] == INF) {
	      dist[v] = dist[nu]+1;
	      t += map[v]*dist[v];
	      q.push(v);
	    }
	  }
	}
      }
      if (t < best) {
	best = t;
	sol = 1<<i | 1<<j | 1<<k | 1<<l | 1<<m;
      }
    }
    bool first = true;
    for (int i = 0; i < MAXN; ++i) {
      if (sol&(1<<i)) {
	if (first) first = false;
	else cout << ' ';
	cout << i;
      }
    }
    cout << endl;
  }
}
  