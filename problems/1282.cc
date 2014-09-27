#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
void buildB(const string & P, vector<int> & B) {
  int l = P.size();
  B = vector<int>(l+1, -1);
  int i = 0, j = -1;
  while (i < l) {
    while (j != -1 and P[i] != P[j]) j = B[j];
    ++i;
    ++j;
    B[i] = j;
  }
}

void match(const string & S, const string & P, const vector<int> & B) {
  int i = 0, j = 0;
  int l = S.size();
  int k = P.size();
  while (i < l) {
    while (j != -1 and S[i] != P[j]) j = B[j];
    ++j;
    ++i;
    if (j == k) {
      cout << " match of P at " << i-k << endl;
      j = B[j];
    }
  }
}

const int maxsize = 200100*2;

int main() {
  int n;
  while (cin >> n) {
    string pattern;
    cin >> pattern;
    string rev(pattern);
    reverse(rev.begin(), rev.end());
    
    string s1 = "0";
    string s2 = "1";
    
    ll fib1 = (pattern == s1);
    ll fib2 = (pattern == s2);
    
    string final = s2+s1;
    while (final.size() < maxsize) {
      s1 = s2;
      s2 = final;
      final = s2+s1;
    }
    vector<int> b;
    buildB(pattern, b);
    
    
  }
}