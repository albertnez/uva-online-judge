#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> VI;

VI SA, RA, lcs;
VI lengths;
string S;
int gap, N, M;
bool cmp(int i, int j) {
  if (RA[i] != RA[j]) return RA[i] < RA[j];
  i += gap;
  j += gap;
  if (i < N and j < N) return RA[i] < RA[j];
  return i > j;
}
void buildSA() {
  N = S.size();
  SA = RA = VI(N);
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
void buildlcs() {
  lcs = VI(N, 0);
  VI pre(N,-1);
  for (int i = 1; i < N; ++i) pre[SA[i]] = SA[i-1];
  int act = 0;
  for (int i = 0; i < N; ++i) {
    if (pre[i] == -1) lcs[i] = 0;
    else {
      while (S[i+act] == S[pre[i]+act]) ++act;
      lcs[i] = act;
      act = max(act-1, 0);
    }
  }
  VI tmp(lcs);
  for (int i = 0; i < N; ++i) lcs[i] = tmp[SA[i]];
}
int getOwner(int i) {
  int n = 0;
  while (i >= 0) i -= lengths[n++];
  return n-1;
}
void prints(const multiset<int> & s) {
  for (multiset<int>::iterator it = s.begin(); it != s.end(); ++it) {
    cout << ' ' << *it;
  }
  cout << endl;
}
void getStrings() {
  int i = 0, total = 0, ans = 0;
  int target = (M+2)/2;
  VI reps(M, 0);
  multiset<int> minimumlcs;
  set<string> strings;
  
  for (int j = 0; j < N; ++j) {
    minimumlcs.insert(lcs[j]);
    int o = getOwner(SA[j]);
    if (!(reps[o]++)) {
      if (++total == target) {
        do {
          minimumlcs.erase(minimumlcs.find(lcs[i]));
          
          int now = *minimumlcs.begin();
          if (now > ans) {
            strings.clear();
            ans = now;
          }
          if (now == ans) {
            strings.insert(S.substr(SA[j], ans));
          }
          
          int o2 = getOwner(SA[i]);
          ++i;
          if (!(--reps[o2])) --total;
        } while (total == target);
      }
    }
  }
  if (strings.size() == 0 or *strings.begin() == "") cout << "?" << endl;
  else {
    for (set<string>::iterator it = strings.begin(); it != strings.end(); ++it)
      cout << *it << endl;
  }
}
int main() {
  bool first = true;
  while (cin >> M and M) {
    if (first) first = false;
    else cout << endl;
    lengths = VI(M);
    S = "";
    char c = '$';
    for (int i = 0; i < M; ++i) {
      string s; cin >> s;
      s += c;
      --c;
      lengths[i] = s.size();
      S += s;
    }
    buildSA();
    buildlcs();
    getStrings();
  }
}