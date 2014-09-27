#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent, lid;
vector<int> v;
vector<int> idton;

void print(int i) {
  if (i == -1) return;
  print(parent[i]);
  cout << ", " << idton[v[i]];
}

int main() {
  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    int n, p, q;
    cin >> n >> p >> q;
    ++p; ++q;
    vector<int> id(n*n+1, -1);
    idton.assign(n*n+1, -1);
    int act = 0;
    for (int i = 0; i < p; ++i) {
      int k; cin >> k;
      idton[act] = k;
      id[k] = act++;
    }
    
    v.clear();
    for (int i = 0; i < q; ++i) {
      int k; cin >> k;
      if (id[k] >= 0) v.push_back(id[k]);
    }
    vector<int> lis;
    int l = v.size();
    parent.assign(l, -1);
    
    for (int i = 0; i < l; ++i) {
      int pos = int(lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin());
//       cout << "pos: " << pos << endl;
      if (pos == int(lis.size())) {
        lis.push_back(v[i]);
        lid.push_back(i);
      }
      else {
        lis[pos] = v[i];
        lid[pos] = i;
      }
      
      parent[i] = (pos > 0 ? lid[pos-1] : -1);
    }
    
    cout << "Case " << ++ncase << ": " << lis.size() << endl;
    print(lid[lis.size()-1]);
    cout << endl;
  }
}