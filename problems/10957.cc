#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;

int N = 3, M = 9;
int OK;
int count = 0;
void bt(int i, int j, MI & m, VI rows, VI cols, MI sq) {
  if (count > 1) return;
  if (i == M) {
    ++count;
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
      bt(i+(j+1)/M, (j+1)%M, m, crows, ccols, csq);
      if (count > 1) return;
      pos -= p;
    }
    m[i][j] = 0;
  }
}

const string status[4] = {"Unique.", "Ambiguous.", "Illegal.", "Impossible."};
int main() {
  int ncase = 0;
  MI m(M, VI(M));
  OK = (1 << M)-1;
  while (cin >> m[0][0]) {
    count = 0;
    VI rows(M), cols(M);
    MI sq(N, VI(N));
    bool ilegal = false;
    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < M; ++j) {
        if (i or j) cin >> m[i][j];
        if (m[i][j] != 0) {
          int p = 1<<(m[i][j]-1);
          ilegal |= (rows[i] | cols[j] | sq[i/N][j/N]) & p;
          rows[i] |= p;
          cols[j] |= p;
          sq[i/N][j/N] |= p;
        }
      }
    }
    cout << "Case " << ++ncase << ": ";
    if (!ilegal) bt(0, 0, m, rows, cols, sq);
    if (count == 1) cout << status[0] << endl;
    else if (count > 1) cout << status[1] << endl;
    else if (ilegal) cout << status[2] << endl;
    else cout << status[3] << endl;
  }
}
