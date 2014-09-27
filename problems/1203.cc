#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> Vi;
const int MAX = 3001;
int main() {
  string s;
  priority_queue<ii, vector<ii>, greater<ii> > pq;
  Vi v(MAX);
  while (cin >> s and s != "#") {
    int id, t;
    cin >> id >> t;
    v[id] = t;
    pq.push(ii(t, id));    
  }
  int k; cin >> k;
  while (k--) {
    ii f = pq.top(); pq.pop();
    cout << f.second << endl;
    f.first += v[f.second];
    pq.push(f);
  }
}