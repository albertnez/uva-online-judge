#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, t, m;
  cin >> n >> t >> m;
  vector<vector<bool> > ac(t, vector<bool> (n, false));
  vector<int> last(n, -1);
  vector<int> lastt(n, 0);
  while (m--) {
    int tm, id;
    char p;
    string vr;
    cin >> tm >> id >> p >> vr;
    int pn = p-'A';
    --id;
    if (vr == "Yes" and !ac[id][pn]) {
      ac[id][pn] = true;
      last[pn] = id;
      lastt[pn] = tm;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << char('A'+i) << ' ';
    if (last[i] == -1) cout << "- -" << endl;
    else cout << lastt[i] << ' ' << last[i]+1 << endl;
  }
}