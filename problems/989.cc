#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;

int N, M;
int OK;
bool bt(int i, int j, MI & m, VI rows, VI cols, MI sq) {
  if (i == M) {
    for (int k = 0; k < M; ++k) {
      for (int l = 0; l < M; ++l) {
        cout << (l?" ":"") << m[k][l];
      }
      cout << endl;
    }
    return true;
  }
  else if (m[i][j] != 0) { 
    return bt(i+(j+1)/M, (j+1)%M, m, rows, cols, sq);
  }
  else {
    int pos = OK & ~(rows[i] | cols[j] | sq[i/N][j/N]);
    while (pos) {
      int p = pos & -pos;
      int n = 0;
      while ((1<<n) != p) ++n;
      m[i][j] = n+1;
      VI crows = rows;
      VI ccols = cols;
      MI csq = sq;
      crows[i] |= p;
      ccols[j] |= p;
      csq[i/N][j/N] |= p;
      if (bt(i+(j+1)/M, (j+1)%M, m, crows, ccols, csq))
        return true;
      pos -= p;
    }
    m[i][j] = 0;
  }
  return false;
}

int main() {
  bool first = true;
  while (cin >> N) {
    if (first) first = false;
    else cout << endl;
    M = N*N;
    OK = (1 << M)-1;
    MI m(M, VI(M));
    VI rows(M), cols(M);
    MI sq(N, VI(N));
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < M; ++j) {
        cin >> m[i][j];
        if (m[i][j] != 0) {
          rows[i] |= (1<<(m[i][j]-1));
          cols[j] |= (1<<(m[i][j]-1));
          sq[i/N][j/N] |= (1<<(m[i][j]-1));
        }
      }
    }
    if (!bt(0, 0, m, rows, cols, sq))
      cout << "NO SOLUTION" << endl;
  }
}
