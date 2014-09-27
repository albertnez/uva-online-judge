#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> VI;
const int maxn = 100005;
int size;
VI mintree;
VI maxtree;

//returns blocks with height >= h
int query(int p, int i, int j, int L, int R, int h) {
  if (i >= R or j <= L) return 0;
  if (mintree[p] > h) return 0;
  if (maxtree[p] <= h) return min(j, R) - max(L, i);
  return query(p*2, i, j, L, (L+R)/2, h) + query(p*2+1, i, j, (L+R)/2, R, h);
}

void update(int p, int i, int j, int L, int R, int h) {
  if (i >= R or j <= L) return;
  maxtree[p] = max(maxtree[p], h);
  if (i <= L and j >= R) mintree[p] = max(mintree[p], h);
  else {
    update(p*2, i, j, L, (L+R)/2, h);
    update(p*2+1, i, j, (L+R)/2, R, h);
    mintree[p] = max(mintree[p], min(mintree[p*2], mintree[p*2+1]));
  }
}
int main() {
  size = 1;
  while (size < maxn) size *= 2;
  size *= 2;
  int T; cin >> T;
  while (T--) {
    int n;
    cin >> n;
    mintree = maxtree = VI(size, 0);
    int total = 0;
    while (n--) {
      int l, r, h;
      cin >> l >> r >> h;
      total += query(1, l, r, 0, maxn, h);
      update(1, l, r, 0, maxn, h);
    }
    cout << total << endl;
  }
}
