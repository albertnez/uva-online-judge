#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VII;

VII memo;
VII balls;
VII acum;

int N;
const int inf = -1e9;

int f(int r, int c) {
  if (r < 0 or c >= N) return 0;
  if (memo[r][c] != -inf) return memo[r][c];
  return memo[r][c] = max(acum[r][c] + f(r, c+1), f(r-1, c));
}


int main() {
  while (cin >> N and N) {
    balls = acum = VII(N, VI(N, 0));
    memo = VII(N, VI(N, -inf));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j <= i; ++j) {
        cin >> balls[i-j][j];
      }
    }
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
      acum[i][j] = balls[i][j];
      if (i > 0) acum[i][j] += acum[i-1][j];
    }
    cout << f(N-1, 0) << endl;
    
  }
}