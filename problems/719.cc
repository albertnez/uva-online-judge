#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> VI;

int N;
VI SA, RA;
string S;
int gap;
bool cmp(int i, int j) {
  if (RA[i] != RA[j]) return RA[i] < RA[j];
  int ni = (i+gap)%N;
  int nj = (j+gap)%N;
  return RA[ni] < RA[nj];
}
void buildSA() {
  N = S.size();
  RA = VI(N);
  SA = VI(N);
  for (int i = 0; i < N; ++i) SA[i] = i;
  for (int i = 0; i < N; ++i) RA[i] = S[i];
  for (gap = 1; gap < N; gap <<= 1) {
    sort(SA.begin(), SA.end(), cmp);
    VI tRA(N, 0);
    for (int i = 1; i < N; ++i) tRA[i] = tRA[i-1] + cmp(SA[i-1], SA[i]);
    for (int i = 0; i < N; ++i) RA[SA[i]] = tRA[i];
    
    if (RA[SA[N-1]] == N-1) return;
  }
}

int main() {
  int T; cin >> T;
  while (T--) {
    cin >> S;
    buildSA();
    
    int mn = SA[0];
    for (int i = 1; i < N; ++i) {
      if (RA[SA[i]] == RA[mn]) mn = min(mn, SA[i]);
    }
    cout << mn + 1 << endl;
  }
}