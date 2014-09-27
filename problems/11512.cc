#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> VI;

int N;
int gap;
string S;
VI RA;
VI SA;
bool cmp(int i, int j) {
  if (RA[i] != RA[j])
    return RA[i] < RA[j];
  i += gap;
  j += gap;
  if (i < N and j < N) return RA[i] < RA[j];
  else return i > j;
}

void buildSA() {
  N = S.size();
  RA = SA = VI(N);
  for (int i = 0; i < N; ++i) SA[i] = i;
  for (int i = 0; i < N; ++i) RA[i] = S[i];
  for (gap = 1; gap < N; gap <<= 1) {
    sort(SA.begin(), SA.end(), cmp);
    VI newRA = VI(N, 0);
    for (int i = 1; i < N; ++i) newRA[i] = newRA[i-1] + cmp(SA[i-1], SA[i]);
    for (int i = 0; i < N; ++i) RA[SA[i]] = newRA[i];
    if (RA[SA[N-1]] == N-1) break;
  }
}

pair<int,string> lcp() {
  string best = "";
  int act = 0;
  int mx = 0;
  int reps = 0;
  VI pre(N, -1);
  for (int i = 1; i < N; ++i) pre[SA[i]] = SA[i-1]; 
  for (int i = 0; i < N; ++i) {
    if (pre[i] < 0) continue;
    while (S[i+act] == S[pre[i]+act]) act++;
    if (act > mx) {
      best = S.substr(i, act);
      mx = act;
      reps = 2;
    }
    else if (act == mx) {
      string s = S.substr(i,act);
      if (s == best) ++reps;
      else if (s < best) {
        reps = 2;
        best = min(best, s);
      }
    }
    act = max(act-1, 0);
      
  }
  if (best.size() == 0) reps = 0;
  return pair<int,string>(reps, best);
}

int main() {
  int T; cin >> T;
  while (T--) {
    cin >> S;
    buildSA();
    pair<int,string> sol = lcp();
    if (!sol.first) cout << "No repetitions found!" << endl;
    else cout << sol.second << " " << sol.first << endl;
  }
}