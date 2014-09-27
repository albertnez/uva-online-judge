#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vi;
int N;
Vi v, st;

int left(int n) {return n<<1; }
int right(int n) {return (n<<1)+1; }

void build(int i,int l,int r) {
  if (l == r)
    st[i] = v[l];
  else {
    build(left(i), l, (l+r)/2);
    build(right(i), (l+r)/2+1, r);
    st[i] = st[left(i)] * st[right(i)];
  }
}

int query(int p, int l, int r, int i, int j) {
  if (i > r or j < l) return -2;
  if (i <= l and j >= r) return st[p];
  int p1 = query(left(p), l, (l+r)/2, i, j);
  int p2 = query(right(p), (l+r)/2+1, r, i, j);
  if (p1==-2) return p2;
  if (p2==-2) return p1;
  return p2*p1;
}

void change(int p, int n) {
  if (n > 0) n = 1;
  else if (n < 0) n = -1;        
  
  int i = 1;
  int l = 0, r = N-1;
  while (l != r) {
    if ((l+r)/2 >= p) {
      r = (l+r)/2;
      i = left(i);
    }
    else {
      l = (l+r)/2+1;
      i = right(i);
    }
  }
      
  st[i] = n;
  i>>=1;
  while (i>=1) {
    st[i] = st[left(i)] * st[right(i)];
    i>>=1;
  }
}

void print() {}

int main() {
  int k;
  while (cin >> N >> k) {
    v.assign(N, 0);
    st.assign(4*N, -2);
    for (int i = 0; i < N; ++i) {
      int k; cin >> k;
      if (!k) v[i] = 0;
      else if (k > 0) v[i] = 1;
      else v[i] = -1;     
    }
    build(1, 0, N-1);
    


    while (k--) {
      char c;
      int a, b;
      cin >> c >> a >> b;
      if (c == 'C')
        change(a-1, b);
      else {
        int ans = query(1, 0, N-1, a-1, b-1);
        if (!ans) cout << 0;
        else if (ans > 0) cout << '+';
        else cout << '-';
      }
    }
    cout << endl;
  }
}