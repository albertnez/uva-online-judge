#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;

const int inf = 1e9;
const int maxn = 1001;
int P, V;

int valid[maxn][maxn];
int atk[maxn], ene[maxn], def[maxn];
int memo[maxn][maxn];

int f(int i, int j) {
  if (j == V) return 0;
  if (i == P) return inf;
  if (memo[i][j] != -1) return memo[i][j];
  
  int &ans = memo[i][j] = f(i+1,j);
  if (valid[i][j] and atk[i] >= def[j]) ans = min(ans, f(i+1,j+1) + ene[i]);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  int e;
  while (cin >> P >> V >> e and (P|V|e)) {
    memset(memo, -1, sizeof memo);
    memset(valid, 0, sizeof valid);
    
    map<string,int> msi;
    int act = 0;
    
    for (int i = 0; i < P; ++i) {
      string s;
      cin >> s >> atk[i] >> ene[i];
      msi[s] = act++;
    }
    for (int i = 0; i < V; ++i) {
      string s;
      cin >> s >> def[i] >> s;
      
      size_t st = 0, end = s.find_first_of(',', st);
      while (string::npos != end) {
        valid[msi[s.substr(st, end-st)]][i] = 1;
        st = end+1;
        end = s.find_first_of(',', st);
      }
      valid[msi[s.substr(st)]][i] = 1;
    }
    
    
    if (f(0,0) <= e) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
  