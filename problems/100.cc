#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vi;

const int maxn = 1e6;
Vi v(1e6, -1);

int f(unsigned int n) {
  if (n == 1) return 1;
  else if (n >= maxn) return 1 + (n%2 ? f(3*n+1) : f(n/2));
  else if (v[n] < 0) return v[n] = 1 + (n%2 ? f(3*n+1) : f(n/2));
  else return v[n];
}



Vi tree(4e6, -1);

void build(int p, int L, int R) {
  if (L == R) tree[p] = v[L];
  else {
    build(p*2, L, (L+R)/2);
    build(p*2+1, (L+R)/2+1, R);
    tree[p] = max(tree[p*2], tree[p*2+1]);
  }
}

int query(int p, int L, int R, int i, int j) {
  if (i > R or j < L or L > R) return -1;
  if (i <= L and j >= R) return tree[p];
  
  int p1 = query(p*2, L, (L+R)/2, i, j);
  int p2 = query(p*2+1, (L+R)/2+1, R, i, j);
  return max(p1, p2);  
}


int main() {
  v[1] = 1;
  for (int i = 1; i < maxn; ++i)
    f(i);
  
  build(1, 0, maxn-1);
  int a, b;
  while (cin >> a >> b) {
    cout << a << ' ' << b << ' ' << query(1, 0, maxn-1, min(a,b), max(a,b)) << endl;
  }
  
}