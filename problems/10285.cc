#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;
typedef pair<int, pi> ti;

typedef vector<ti> Vti;
typedef vector<int> Vi;
typedef vector<Vi> Mi;

int di[4] = {0, -1, 0, 1};
int dj[4] = {1, 0, -1, 0};

int main() {
  int T; cin >> T;
  while (T--) {
    string name;
    int r, c;
    cin >> name >> r  >> c;
    Mi m(r, Vi(c, 1)), paths(m);
    Vti sorted;
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) {
        cin >> m[i][j];
        sorted.push_back(ti(-m[i][j], pi(i, j)));
      }
      
    int longest = 1;
    
    sort(sorted.begin(), sorted.end());
    for (int n = 0; n < sorted.size(); ++n) {
      int h = -sorted[n].first, i = sorted[n].second.first, j = sorted[n].second.second;
      for (int x = 0; x < 4; ++x) {
        int ni = i+di[x], nj = j+dj[x];
        if (ni >= 0 and ni < r and nj >= 0 and nj < c and m[ni][nj] < h) {
          paths[ni][nj] = max(paths[ni][nj], paths[i][j]+1);
          longest = max(longest, paths[ni][nj]);
        }          
      }
    }
    cout << name << ": " << longest << endl;
  }
}