#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vi;
typedef long long ll;

int maxn = 1e5+10;

int mod;

int N, B;

Vi tree;
Vi pots(maxn);

// int fexp(int n) {
//   if (n == 0) return 1;
//   if (n == 1) return B;
//   
//   ll m = fexp(n/2)%mod;
//   ll tmp = (m*m)%mod;
//   if (n&1) tmp = (tmp*B)%mod;
//   return tmp;
// }

int fexp(int n) {
  return pots[n];
}

int query(int n, int L, int R, int i, int j) {
  if (i > R or j < L or L > R) return 0;
  if (i <= L and j >= R) {
    ll tmp = tree[n];
    tmp = (tmp*fexp(j-R))%mod;
    return tmp;
  }
  
  ll l = query(2*n, L, (L+R)/2, i, j);
  ll r = query(2*n+1, (L+R)/2+1, R, i, j);
  
  return (l+r)%mod;
}

/*
int N; //tamaño interval tree potencia de 2

void change(int n, int x)
{
  n += N;
  tree[n] = x;
  
  n /= 2;
  while(n != 0)
  {
    tree[n] = tree[n*2]+tree[n*2+1];
    n /= 2;
  }
}
*/
void change(int n, int L, int R, int i, int x) {
  if (i > R or i < L or L > R) return;
  if (L == R) {
    tree[n] = x%mod;
    return ;
  }
  
  if (i < (L+R)/2+1) change(n*2, L, (L+R)/2, i, x);
  else change(n*2+1, (L+R)/2+1, R, i, x);
  
  ll l = tree[n*2];
  ll r = tree[n*2+1];
    
  ll exp = fexp(R - ((L+R)/2+1) +1);
  l = (l*exp)%mod;
  l = (l+r)%mod;
  tree[n] = l;
}

void precalcpot() {
  pots[0] = 1;
  pots[1] = B%mod;
  for (int i = 2; i < maxn; ++i) {
    pots[i] = (ll(pots[i-1])*ll(B))%mod;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int q;
  while (cin >> B >> mod >> N >> q and (B|mod|N|q)) {
    
    precalcpot();
     // int n2 = 1;
   //   while(n2 < N) n2 *= 2;
  //    N = n2;
    int n2 = 1;
    while (n2 < N) n2 <<= 1;
    N = n2;
    tree.assign(N*2, 0);
    
    while (q--) {
      char op;
      int a, b;
      cin >> op >> a >> b; 
            
      
      if (op == 'E') change(1, 0, N-1, a-1, b);
      else cout << query(1, 0, N-1, a-1, b-1) << endl;
    }
    cout << '-' << endl;
  }
}