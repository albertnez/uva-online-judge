#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;

int N, K;
VI d, ls, rs;

const int maxn = 201;
const int maxk = 31;
int memo[maxn][maxk];
int path[maxn][maxk];
// int path[maxn];

int f(int n, int k) {
  if (n==N) return 0;
  if (k == 0) {
    int sum = 0;
    for (int i = n; i < N; ++i) {
      sum += d[i]-d[n-1];
    }
    return sum;
  }
  if (memo[n][k] != -1) return memo[n][k];
  
  int &ans = memo[n][k] = 1e9;
  
  for (int i = n; i < N; ++i) {
    int sum = 0;
    for (int j = n; j < i; ++j) {
      if (d[j]-d[n-1] < d[i]-d[j]) sum += d[j] - d[n-1];
      else sum += d[i] - d[j];
    }
    
    int tmp = f(i+1, k-1)+sum;
    if (tmp < ans) {
      path[n-1][k] = i;
      ans = tmp;
    }
  }
  return ans;
  
}


void print(int n, int id, int l) {
  if (id == -1) return;
  
  int nxt = path[id][K-n];
  int r = N;
  if (nxt != -1) {
    r = id;
    while (r < nxt and d[r]-d[id] < d[nxt]-d[r]) r++;
  }
  
  if (l == r) cout << "Depot " << n << " at restaurant " << id+1 << " serves restaurant " << l << endl;
  else cout << "Depot " << n << " at restaurant " << id+1 << " serves restaurants " << l << " to " << r << endl;

  print(n+1, path[id][K-n], r+1);
}

int main() {
  int ncase = 0;
  while (cin >> N >> K and (N|K)) {
    memset(memo, -1, sizeof memo);
    memset(path, -1, sizeof path);
    
    d = VI(N);
    ls.assign(N+1, 0);
    rs.assign(N+1, 0);
    for (int i = 0; i < N; ++i)
      cin >> d[i];
    
    int ans = 1e9;
    
    int sp = 0;
    for (int i = 0; i < N; ++i) {
      int sum = 0;
      for (int j = 0; j < i; ++j) sum += d[i]-d[j];
      int tmp = f(i+1, K-1)+sum;
      if (tmp < ans) {
        sp = i;
        ans = tmp;
      }
    }
    
    
    cout << "Chain " << ++ncase << endl;
    print(1, sp, 1);
    cout << "Total distance sum = " << ans << endl << endl;
    
  }
}