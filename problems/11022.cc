#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;


const int maxn = 81;
int B[maxn];
int memo[maxn][maxn];
string a, b, s;

int f(int i, int j);

int count(const string& s) {
  int n = s.size();
  char last = '.';
  for (int i = 0; i < int(s.size()); ++i) {
    if (s[i] == last) --n;
    last = s[i];
  }
  return n;
}

void pre() {
  int m = b.size();
  int i = 0, j = -1;
  B[0] = j;
  while (i < m) {
    while (j >= 0 and b[i] != b[j]) j = B[j];
    ++i; ++j;
    B[i] = j;
  } 
}

int calc() {
  int res = 0;
  int n = a.size(), m = b.size();
  int i = 0, j = 0;
  while (i < n) {
    while (j >= 0 and a[i] != b[j]) j = B[j];
    ++i; ++j;
    if (j == m) {
      ++res;
      j = B[j];
    }
  }
  
  return m/(res-1);
}

int kmp(int i, int j) {
  b = s.substr(i, j-i+1);
  a = b+b;
  pre();
  
  int ans = calc();
  if (i+ans-1 == j) return ans;
  return f(i, i+ans-1);
}

// ABCDEF
int f(int i, int j) {
  if (i == j) return 1;
  if (memo[i][j] != -1) return memo[i][j];
  int &ans = memo[i][j];
  
  ans = kmp(i, j);
  for (int k = i; k < j; ++k)
    ans = min(ans, f(i, k) + f(k+1, j));

  return ans;
}

int main() {
  while (getline(cin,s) and s != "*") {
    memset(memo, -1, sizeof memo);
    cout << f(0, s.size()-1) << endl;
  }
}