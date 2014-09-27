#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vi;

const int MAX = 1024000;
Vi tmpv(MAX);
Vi tree, upd;
int N;

void build(int p, int L, int R) {
  if (L == R)
    tree[p] = tmpv[L];
  else {
    build(p*2, L, (L+R)/2);
    build(p*2+1, (L+R)/2+1, R);
    tree[p] = tree[p*2] + tree[p*2+1];
  }
}

int joinUpdate(int p, int c) {
  if (p == 3) {
    if (c == 1) return 2;
    if (c == 2) return 1;
    if (c == 0) return 3;
    return 0;
  }
  return p;
}

void propagate(int p, int L, int R) {
  if (!upd[p]) return;
   
  if (upd[p] == 1) tree[p] = (R-L+1);
  else if (upd[p] == 2) tree[p] = 0;
  else if (upd[p] == 3) tree[p] = (R-L+1) - tree[p];
  
  if (L < R) {
    int c1 = 2*p, c2 = 2*p+1;
    upd[c1] = joinUpdate(upd[p], upd[c1]);
    upd[c2] = joinUpdate(upd[p], upd[c2]);
  }
  upd[p] = 0;

}

int rmq(int p, int L, int R, int i, int j) {
  if (L > R or i > R or j < L) return 0; // outsite
  
  propagate(p, L, R);
  
  if (L >= i and R <= j) return tree[p]; // inside query range
  
  
  int p1 = rmq(p*2, L, (L+R)/2, i, j);
  int p2 = rmq(p*2+1, (L+R)/2+1, R, i, j);
   
  return p1+p2;
}

void update(int p, int L, int R, int i, int j, int t) {
  propagate(p, L, R);
  if (L > R or i > R or j < L) return;
  
  
  if (i <= L and j >= R) {
    upd[p] = t;
    propagate(p, L, R);
    return;
  }
  
  update(2*p, L, (R+L)/2, i, j, t);
  update(2*p+1, (L+R)/2+1, R, i, j, t);
  tree[p] = tree[2*p] + tree[2*p+1];
}


void print(const Vi &v, int n) {
  for (int i = 1; i < n; ++i)
    cout << v[i] << ' ';
  cout << endl;
}

/*
F a b, means, mutate the pirates from index a to b to Buccaneer Pirates.
E a b, means, mutate the pirates from index a to b to Barbary Pirates.
I a b, means, mutate the pirates from index a to b to inverse pirates.
S a b, means, “God’s query” God is asking a question: “Tell me, how many Buccaneer pirates are there from index a to b?”
*/

int main() {
  int T, ncase = 0; cin >> T;
  while (T--) {
    cout << "Case " << ++ncase << ":" << endl;
    
    N = 0;
    int ninp; cin >> ninp;
    int ind = 0;
    for (int i = 0; i < ninp; ++i) {
      int ntimes; cin >> ntimes;
      string s; cin >> s;
      for (int j = 0; j < ntimes; ++j) {
        for (int k = 0; k < s.size(); ++k) {
          tmpv[ind++] = s[k]-'0';
        }
      }
    }
    N = ind;
//     print(tmpv, N);
    tree.assign(4*N, 0);
    upd.assign(4*N, 0);
//     cout << "wololo" << endl;
    build(1, 0, N-1);
    int nop; cin >> nop;
    int godq = 0;
    while (nop--) {
      char op;
      int a, b;
      cin >> op >> a >> b;
      if (op == 'S') {
        cout << "Q" << ++godq << ": " << rmq(1, 0, N-1, a, b) << endl;
      } else {
        int t = 1;
        if (op == 'E') t = 2;
        else if (op == 'I') t = 3;
        update(1, 0, N-1, a, b, t);
      }
    }
  }
}