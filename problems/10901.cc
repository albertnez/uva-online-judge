#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> Vi;
int main() {
  int T; cin >> T;
  while (T--) {
    int n, t, m;
    cin >> n >> t >> m;
    Vi times(m), pos(m), sol(m);
    for (int i = 0; i < m; ++i) {
      string s;
      cin >> times[i] >> s;
      if (s == "left") pos[i] = 0;
      else pos[i] = 1;
    }
    
    vector<queue<int> > vq(2);
    int time = times[0];
    int ind = 0;
    int p = 0;
        
    while (ind < m or !vq[0].empty() or !vq[1].empty()) {  
      if (ind < m and vq[0].empty() and vq[1].empty() and time < times[ind])
        time = times[ind];
      while (ind < m and times[ind] <= time) {
        vq[pos[ind]].push(ind);
        ++ind;
      }
      
      bool change = (!vq[0].empty() or !vq[1].empty());
      for (int i = 0; i < n and !vq[p].empty(); ++i) {
        sol[vq[p].front()] = time+t;
        vq[p].pop();
      }
     // p = 1-p;
      if (change) {
        p = 1-p;
        time += t;
      }
    }
    
    for (int i = 0; i < m; ++i)
      cout << sol[i] << endl;
    if (T) cout << endl;
    
  }
}