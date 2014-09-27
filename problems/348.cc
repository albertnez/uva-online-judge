#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 11;
int N; 
ll c[maxn];


int memop[maxn][maxn]; // describes de point where (i, j) divides
ll memo[maxn][maxn];
ll inf = 1e17;

ll f(int i, int j, int n) {
  if (i == j) return 0;
  if (memo[i][j] != -1) return memo[i][j];
  
  ll &ans = memo[i][j] = inf;
  int index = i;
  for (int k = i; k < j; ++k) {
    ll last = ans;
    ans = min(ans, f(i,k, n-1)+f(k+1,j, n-1)+c[i]*c[k+1]*c[j+1]);
    if (ans < last) index = k;
  }
//   cout << "steps[" << i << ' ' << j << "] = " << n << endl;
  
  memop[i][j] = index;
  
  return ans;
}

void print(int i, int j) {
  if (i == j) cout << "A" << i+1;
//   else if (i+1 == j) cout << " A" << i << " x A" << j;
  else {
    cout << "(";
    int k = memop[i][j];
    print(i, k);
    cout << " x ";
    print(k+1, j);
    cout << ")";
  }
}


int main() {
  int ncase = 0;
  while (cin >> N and N) {
    memset(memo, -1, sizeof memo);
    
    cin >> c[0];
    for (int i = 1; i < N; ++i)
      cin >> c[i] >> c[i];
    cin >> c[N];
    
    f(0, N-1, N-2);

    cout << "Case " << ++ncase << ": ";
//     parent();
    print(0, N-1);
    cout << endl;
   
  }
}