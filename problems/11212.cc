#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef vector<int> VI;
const int maxd = 3;
int n;
vector<int> sol;
map<vector<int>, int> distt, dists;
int ans;

void print(const VI &v) {
  for (int i = 0; i < int(v.size()); ++i) cout << ' ' << v[i];
  cout << endl;
}

void bfs2(){
  queue<VI> q;
  distt.clear();
  distt[sol] = 0;
  q.push(sol);
  while (!q.empty()) {
    VI u = q.front(); q.pop();
    int d = distt[u];
    if (d == maxd) break;
    if (dists.find(u) != dists.end()) {
      ans = d+dists[u];
      break;
    }
    //search
    for (int i = 0; i < n; ++i)
    for (int j = i; j < n; ++j) if (i != 0 or j != n-1) {
      VI aux(n-(j-i+1)); //array with books not
      for (int k = 0; k < i; ++k) aux[k] = u[k];
      for (int k = j+1; k < n; ++k) aux[k-(j-i+1)] = u[k];
      
      for (int k = 0; k < n-(j-i+1)+1; ++k) { // every place we can put the cut
        VI tmp(n);
        int actc = 0, actn = 0, ind = 0;
        while (ind < n) { //build new library
          if (ind < k or ind >= k+(j-i+1)) tmp[ind] = aux[actn++]; //not cut
          else tmp[ind] = u[i+(actc++)]; //cut
          ++ind;
        }

        if (distt.find(tmp) == distt.end()) {
          distt[tmp] = d+1;
          q.push(tmp);

        }
      }
    }
  }
}

void bfs(VI &v) {
  queue<VI> q;
  dists.clear();
  dists[v] = 0;
  q.push(v);
  while (!q.empty()) {
    VI u = q.front(); q.pop();
    int d = dists[u];
    if (d == maxd) break;
    if (u == sol) {
      ans = d;
      break;
    }
    //search
    
    for (int i = 0; i < n; ++i)
    for (int j = i; j < n; ++j) if (i != 0 or j != n-1) {
      VI aux(n-(j-i+1)); //array with books not
      for (int k = 0; k < i; ++k) aux[k] = u[k];
      for (int k = j+1; k < n; ++k) aux[k-(j-i+1)] = u[k];
      
      for (int k = 0; k < n-(j-i+1)+1; ++k) { // every place we can put the cut
        VI tmp(n);
        int actc = 0, actn = 0, ind = 0;
        while (ind < n) { //build new library
          if (ind < k or ind >= k+(j-i+1)) tmp[ind] = aux[actn++]; //not cut
          else tmp[ind] = u[i+(actc++)]; //cut
          ++ind;
        }

        if (dists.find(tmp) == dists.end()) {
          dists[tmp] = d+1;
          q.push(tmp);
        }
      }
    }
  }
}

int main() {
  int ncase = 0;
  while (cin >> n and n) {
    ans = -1;
    sol.resize(n);
    VI cur(n);
    
    for (int i = 0; i < n; ++i) sol[i] = i;
    for (int i = 0; i < n; ++i) {cin >> cur[i]; --cur[i]; }
    
    bfs(cur);
    if (ans == -1) bfs2();
    cout << "Case " << ++ncase << ": " << (ans == -1 ? 5 : ans) << endl;
  }
}

                     
                     