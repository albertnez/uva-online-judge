#include <iostream>
#include <vector>
using namespace std;
typedef vector<char> Vc;
typedef vector<Vc> Mc;

void rotate(Mc &a) {
  Mc b = a;
  int n = a.size();
  int m = (a.size())/2;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      int ti = j, tj = n-i-1;
      if (i < m and j >= m)
        tj = n-i-1, ti = j;
      if (i >= m and j > m)
        ti = j, tj = n-i-1;
      if (i >= m and j < m)
        ti = j, tj = n-i-1;
      a[ti][tj] = b[i][j];
    }
}

int same(const Mc &a, const Mc &b) {
  int N = a.size(), n = b.size();
  int t = 0;
  bool ok;
  for (int i = 0; i < N-n+1; ++i)
    for (int j = 0; j < N-n+1; ++j) {
      ok = true;
      for (int k = i; k < i+n and ok; ++k)
        for (int l = j; l < j+n and ok; ++l)
          ok = (a[k][l] == b[k-i][l-j]);     
      if (ok) ++t;        
    }
  return t;
}

int main() {
  int n, N;
  while (cin >> N >> n and (N|n)) {
    Mc a(N, Vc(N)), b(n, Vc(n));
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        cin >> a[i][j];
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        cin >> b[i][j];
     
    cout << same(a,b) << ' ';
    rotate(b);
    cout << same(a,b) << ' ';
    rotate(b);
    cout << same(a,b) << ' ';
    rotate(b);
    cout << same(a,b) << endl;
    
  }
}