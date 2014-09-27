#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> PII;
typedef vector<PII> VPII;


bool cmp(const PII &a, const PII &b) {
  if (a.first > b.first) return true;
  if (a.first == b.first and a.second < b.second) return true;
  return false;
}

bool cmp2(int a, int b) {
  return a <= b;
}


int main() {
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    VPII v(n);
    for (int i = 0; i < n; ++i) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), cmp);
    
    
    vector<int> lis;
    for (int i = 0; i < n; ++i) {
      int p = lower_bound(lis.begin(), lis.end(), v[i].second, cmp2)-lis.begin();
//       cout << "p: " << p << " size: " << lis.size() << endl;
      if (p == int(lis.size())) lis.push_back(v[i].second);
      else lis[p] = v[i].second;

    }
    cout << lis.size() << endl;
  }
}
