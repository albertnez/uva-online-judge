#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<bool> Vb;
typedef vector<Vb> Mb;

typedef pair<int,int> pi;
typedef pair<int, pi> ti;

typedef vector<ti> Vti;

const int maxcn = 101;
const int maxpn = 10;

int main() {
  int T; cin >> T;
  cin.ignore();
  cin.ignore();
  while (T--) {
    Mi sb(maxcn, Vi(maxpn, 0));
    Mb ac(maxcn, Vb(maxpn, false));
    Vi totalt(maxcn, -1);
    Vi totals(maxcn, 0);
    string line;
    while (getline(cin,line) and line != "") {
      istringstream ss(line);
      int cn, pn, t;
      char r;
      ss >> cn >> pn >> t >> r;

      if (totalt[cn] < 0) totalt[cn] = 0;
      
      if (r == 'I') {
        if (!ac[cn][pn])
          sb[cn][pn] += 20;
        
      } else if (r == 'C') {
        if (!ac[cn][pn]) {
          totalt[cn] += t + sb[cn][pn];
          ac[cn][pn] = true;
          ++totals[cn];
        }
      }
    }
    
    Vti vr;
    for (int i = 0; i < maxcn; ++i)
      if (totalt[i] >= 0)
        vr.push_back(ti(-totals[i], pi(totalt[i], i)));
    
    sort(vr.begin(), vr.end());
    
    for (int i = 0; i < vr.size(); ++i)
      cout << vr[i].second.second << ' ' << -vr[i].first << ' ' << vr[i].second.first << endl;
    
    if (T) cout << endl;
  }
}