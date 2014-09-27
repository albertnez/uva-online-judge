#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef vector<int> VI;
// suffix array
VI SA, RA;
string S;
int N;
int gap;
bool cmp(int i, int j) {
  if (RA[i] != RA[j]) return RA[i] < RA[j];
  i += gap;
  j += gap;
  if (i < int(S.size()) and j < int(S.size())) return RA[i] < RA[j];
  return i > j;
}

set<string> strings;


void buildLCP() {
  int n = S.size();
  VI rSA(n);
  for (int i = 0; i < n; ++i) rSA[SA[i]] = i;
  VI phi(n);
  for (int i = 0; i < n; ++i) {
    if (rSA[i]) phi[i] = SA[rSA[i]-1];
    else phi[i] = -1;
  }
  
  int k = 0;
  int maxlcp = 0;
  int maxans = 0;
  for (int i = 0; i < n; ++i) {
    if (phi[i] == -1) k = 0;
    else while (S[i+k] == S[phi[i]+k]) ++k;
    
    maxlcp = max(maxlcp, k);
    if ((i<N)^(phi[i]<N)) {
      if (k > maxans) {
        maxans = k;
        strings.clear();
      }
      if (k == maxans and k) {
        strings.insert(S.substr(i, k));
      }
    }
    k = max(k-1, 0);
  }
}
void buildSA(const string & sa, const string & sb) {
  S = sa + "#" + sb + "$";
  int n = S.size();
  RA = VI(n);
  SA = VI(n);
  for (int i = 0; i < n; ++i) RA[i] = S[i];
  for (int i = 0; i < n; ++i) SA[i] = i;
  
  gap = 1;
  while (gap < n) {
    sort(SA.begin(), SA.end(), cmp);
    
    VI tmp(n, 0);
    for (int i = 1; i < n; ++i) tmp[i] = tmp[i-1] + cmp(SA[i-1], SA[i]);
    for (int i = 0; i < n; ++i) RA[SA[i]] = tmp[i];
    gap <<= 1;
    if (RA[SA[n-1]] == n-1) break;
  }
}



int main() {
  string sa, sb;
  bool first = true;
  while (cin >> sa >> sb) {
    N = sa.size();
    buildSA(sa,sb);
    buildLCP();
    if (first) first = false;
    else cout << endl;
    if (strings.size()) {
      for (set<string>::iterator it = strings.begin(); it != strings.end(); ++it)
        cout << *it << endl;
    }
    else {
      cout << "No common sequence." << endl;
    }
    strings.clear();
    
  }
}