#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;
typedef pair<int,int> II;
typedef vector<II> VII;
typedef vector<VII> MII;

//           B   B   B   B   B
//     | - | 0 | 1 | 2 | 3 | 4 |
//-------------------------------
//   - | 0  -1  -2  -3  -4  -5       inserting spaces
// A 0 |-1   ?   ?   ?
// A 1 |-2   ?   ?   ?
// A 2 |-3   ?   ?   ?
// A 3 |-4


//    deleting

MII p; //parent
string a, b;
int count, pos;

void print(int i, int j) {
  II u = p[i][j];
  if (u.first == -1 and u.second == -1) return;
  print(u.first, u.second);
  if (u.first == i-1 and u.second == j-1) {
    if (a[i-1] != b[j-1]) cout << ++count << " Replace " << pos++ << "," << b[j-1] << endl;
    else pos++; 
  }
  else if (u.first == i-1) cout << ++count << " Delete " <<  pos << endl;
  else if (u.second == j-1) cout << ++count << " Insert " << pos++ << "," << b[j-1] << endl;
}

int numEdits(int i, int j) {
  II u = p[i][j];
  if (u.first == -1 and u.second == -1) return 0;
  int ans = numEdits(u.first, u.second);
  if (u.first == i-1 and u.second == j-1 and a[i-1] == b[j-1]) return ans;
  return ans +1;
}

int main() {
  bool first = true;
  while (getline(cin,a)) {
    getline(cin,b);
    count = 0;
    pos = 1;
    int n = a.size(), m = b.size();
    
    MI t(n+1, VI(m+1, 0));
    p = MII(n+1, VII(m+1, II(-1,-1)));
    
    for (int i = 1; i <= n; ++i) {
      t[i][0] = -i; //Cost of deleting
      p[i][0] = II(i-1, 0);
    }
    for (int j = 1; j <= m; ++j) {
      t[0][j] = -j; //Cost of inserting spaces
      p[0][j] = II(0, j-1);
    }
      
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      p[i][j] = II(i-1, j-1);
      t[i][j] = t[i-1][j-1] + (a[i-1] == b[j-1] ? 0 : -1); // cost of match / missmatch
      if (t[i][j-1]-1 > t[i][j]) {
        t[i][j] = t[i][j-1]-1; // inserting space
        p[i][j] = II(i, j-1);
      }
      if (t[i-1][j]-1 > t[i][j]) {
        t[i][j] = t[i-1][j]-1; // deleting
        p[i][j] = II(i-1, j);
      }
    }

    
    if (first) first = false;
    else cout << endl;
    cout << numEdits(n, m) << endl;
//     cout << "score: " << t[n][m] << endl;
    print(n, m);
  }
}