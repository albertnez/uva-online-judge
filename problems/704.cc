#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef vector<int> VI;
typedef pair<VI,VI> PVI;
typedef long long ll;
const int n = 12;
VI lw(n), rw(n);
int cl[n] = {0,3,4,3,0,5,6,5,0,1,2,1};
int cr[n] = {0,7,8,7,0,9,10,9,0,1,2,1};
ll ans = 5e17;
ll cur = 0;
map<PVI, int> dist;

void print() {
  for (int i = 0; i < n; ++i) cout << (i?" ":"") << lw[i];
  for (int i = 0; i < n; ++i) cout << ' ' << rw[i];
  cout << endl;
}

void updateans(ll a, ll b) {
  ll tmpexp = 1;
  while (tmpexp <= b) tmpexp *= 10;
  ans = min(ans, a*tmpexp+b);
}

//1 left clockwise
//2 right clockwise
//3 left anticlockwise
//4 right anticlockwise
void rotate(int op) {
  if (op == 1) {
    int tmp1 = lw[n-1], tmp2 = lw[n-2];
    for (int i = n-1; i >= 2; --i) lw[i] = lw[i-2];
    lw[1] = tmp1; lw[0] = tmp2;
  }
  else if (op == 2) {
    int tmp1 = rw[0], tmp2 = rw[1];
    for (int i = 0; i < n-2; ++i) rw[i] = rw[i+2];
    rw[n-2] = tmp1; rw[n-1] = tmp2;
  }
  else if (op == 3) {
    int tmp1 = lw[0], tmp2 = lw[1];
    for (int i = 0; i < n-2; ++i) lw[i] = lw[i+2];
    lw[n-2] = tmp1; lw[n-1] = tmp2;
  }
  else if (op == 4) {
    int tmp1 = rw[n-1], tmp2 = rw[n-2];
    for (int i = n-1; i >= 2; --i) rw[i] = rw[i-2];
    rw[1] = tmp1; rw[0] = tmp2;
  }
  
  if (op&1) for (int i = 0; i < 3; ++i) rw[n-i-1] = lw[n-i-1];
  else for (int i = 0; i < 3; ++i) lw[n-i-1] = rw[n-i-1];
}

bool correct() {
  for (int i = 0; i < n; ++i)
    if (lw[i] != cl[i] or rw[i] != cr[i]) return false;
  return true;
}
void f(int n) {
//   cout << "n: " << n << "  cur " << cur << endl;
  if (correct() and cur < ans) ans = cur;
  else if (dist.find(PVI(lw,rw)) != dist.end() and cur >= dist[PVI(lw, rw)]) return;
  else dist[PVI(lw,rw)] = cur;
  
  if (n < 8) {
    for (int i = 1; i <= 4; ++i) {
      rotate(i);
      cur *= 10;
      cur += i;
      f(n+1);
      cur /= 10;
      int t = (i+2)%4;
      if (t == 0) t = 4;
      rotate(t);
    }
  }
}

void frev(int n) {
  if (dist.find(PVI(lw,rw)) != dist.end()) 
    updateans(dist[PVI(lw,rw)], cur);
  
  if (n < 8) {
    for (int i = 1; i <= 4; ++i) {
      rotate(i);
      
      int t = (i+2)%4;
      if (t == 0) t = 4;
      
      int tmp = t;
      int tmpexp = 1;
      while (tmpexp <= cur) tmpexp *= 10;
      cur += tmp*tmpexp;
      
      frev(n+1);
      
      cur = cur%tmpexp;
      rotate(t);
    }
  }
}


int main() {
  int T; cin >> T;
  while (T--) {
    dist.clear();
    cur = 0;
    ans = 5e17;
    for (int i = 0; i < n; ++i) cin >> lw[i];
    for (int i = 0; i < n; ++i) cin >> rw[i];
       
    f(0);
    
    if (ans == 5e17) {
      cur = 0;
      for (int i = 0; i < n; ++i) lw[i] = cl[i];
      for (int i = 0; i < n; ++i) rw[i] = cr[i];
      frev(0);
    }
    
    if (ans == 0) cout << "PUZZLE ALREADY SOLVED" << endl;
    else if (ans == 5e17) cout << "NO SOLUTION WAS FOUND IN 16 STEPS" << endl;
    else cout << ans << endl;
  }
}